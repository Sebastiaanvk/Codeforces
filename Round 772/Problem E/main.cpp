#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Rel{
    int dest;
    int type;
};

vector<list<int>> graph;
vector<int> marks;
vector<int> ordering;
int order_pos;

bool no_answer;

void visit(int x){
    if(marks[x]==2){
        return;
    }
    if(marks[x]==1){
        no_answer = true;
        return;
    }
    marks[x]=1;
    for(auto y:graph[x]){
        visit(y);
    }
    marks[x]=2;
    ordering[order_pos--] = x;

}

void solve(){
    int n,m;
    cin >> n >> m;
    graph.resize(n+1);
    vector<list<Rel>> rels(n+1);
    for(int i=1;i<=m;i++){
        int type,x,y;
        cin >> type >> x >> y;
        rels[x].push_back({y,type});
        rels[y].push_back({x,type});
    }
    vector<char> oris(n+1,'0');
    bool possible = true;



    for(int i=1;i<=n;i++){
        if(oris[i]=='0'){
            oris[i] = 'R';
            queue<Rel> q;
            for(Rel r:rels[i]){
                q.push(r);
                oris[r.dest] = 'L';
                if(r.type==1){
                    graph[r.dest].push_back(1);
                } else {
                    graph[1].push_back(r.dest);
                }
            }
            while(!q.empty()){
                Rel r = q.front();
                q.pop();
                for(Rel r2:rels[r.dest]){
                    if(oris[r2.dest]=='0'){
                        oris[r2.dest] = (oris[r.dest]=='R'?'L':'R');
                        q.push(r2);
                    } else if(oris[r2.dest]==oris[r.dest]){
                        possible = false;
                    }
                    if( (oris[r.dest]=='R'&& r2.type==2)||(oris[r.dest]=='L'&& r2.type==1) ){
                        graph[r.dest].push_back(r2.dest);
                    } else {
                        graph[r2.dest].push_back(r.dest);
                    }
                }
            }
        }
    }
    if(!possible){
        cout << "NO\n";
        return;
    }


    no_answer = false;
    order_pos=n-1;
    for(int i=0;i<=n; i++){
        marks.push_back(0);
    }
    ordering.resize(n);

    for(int i=1;i<=n;i++){
        if(marks[i]=0){
            visit(i);
        }
    }
    if(no_answer){
        cout << "NO\n";
        return;
    }

    vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        pos[ordering[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cout << oris[i] << " " << pos[i] << '\n';
    }

}

int main()
{
    solve();
    return 0;
}
