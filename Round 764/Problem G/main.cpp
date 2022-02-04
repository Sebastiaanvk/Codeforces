#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Edge{
    int dest;
    int weight;
};

void dfs(int vertex,const vector<list<Edge>>& edges, int p, vector<bool>& vertices_reached  ){
    vertices_reached[vertex] = true;
    for(auto e:edges[vertex]){
        if( !vertices_reached[e.dest]&&(e.weight&p)==0 ){
            dfs(e.dest, edges, p, vertices_reached);
        }
    }
}

bool can_remove(const vector<list<Edge>>& edges, int p){
    vector<bool> vertices_reached(edges.size(),false);
    vertices_reached[0]=true;
    dfs(1,edges,p, vertices_reached);
    for(int i=0;i<vertices_reached.size();i++){
        if(!vertices_reached[i]) return false;
    }
    return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<list<Edge>> edges(n+1);
    int max_weight=0;
    for(int i=0; i<m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges[v1].push_back({v2,w});
        edges[v2].push_back({v1,w});
        max_weight=max(max_weight,w);
    }
    int p=1;
    while(max_weight/p>1) p*=2;
    int total = 0;
    while(p>0){
        if(can_remove(edges,p)){
            for( int i=1;i<=n; i++){
                list<Edge>::iterator it = edges[i].begin();
                while(it!=edges[i].end()){
                    if( ( (*it).weight & p)!=0){
                        it = edges[i].erase(it);
                    } else {
                        it++;
                    }
                }
            }
        } else {
            total += p;
        }
        p /= 2;
    }
    cout << total << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
