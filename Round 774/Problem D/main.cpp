#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(int x, const vector<list<int>>& graph, vector<int>& pol ){
    for(auto y:graph[x]){
        if(pol[y]==0){
            pol[y] = (pol[x]==1?2:1);
            dfs(y,graph,pol);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<list<int>> graph(n+1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(n==2){
        cout << 2 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    vector<int> pol(n+1,0);
    pol[1]=1;
    dfs(1,graph, pol);
    int onesum=0;
    for(int x=1;x<=n; x++){
        if(pol[x]==1)
            onesum+=1;
    }
    int goodside=2;
    if(onesum>n-onesum)
        goodside=1;
    cout << max(onesum,n-onesum) << ' ';
    long long answer = 0;
    for(int i=1; i<=n; i++){
        if(pol[i]==goodside){
            answer += graph[i].size();
        } else {
            answer += 1;
        }
    }
    if(onesum==n-onesum){
        long long answer2 = 0;
        for(int i=1; i<=n; i++){
            if(pol[i]!=goodside){
                answer2 += graph[i].size();
            } else {
                answer2 += 1;
            }
        }
        if(answer2<answer){
            goodside = (goodside==2?1:2);
            answer = answer2;
        }
    }
    cout << answer << '\n';
    for(int i=1; i<=n; i++){
        if(pol[i]==goodside){
            cout << graph[i].size() << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    solve();
    return 0;
}
