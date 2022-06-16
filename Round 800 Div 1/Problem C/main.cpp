#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs( int index, vector<map<int,int>>& adj_list,  vector<int>& min_dist, vector<bool>& visited){
    int roads_closed = 0;
    visited[index] = true;
    // distances has the distances of the cities we can reach from current city as keys
    // and the total roads leading to cities with that distance as value.
    map<int,int> distances;
    for(auto const& x:adj_list[index]){
        if( visited[x.first] ){
            roads_closed += x.second;
        }
        dfs(x.first,adj_list,min_dist,visited);
        distances[min_dist[x.first]] += x.second;
    }
    //Check if we should close roads:
    //We go from longest distance to shortest and track the total number of roads with that or bigger distance
    //Then we check at each step if lowering the max distance is worth closing the roads.
    map<int,int>::iterator it = distances.end();



}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<map<int,int>> adj_list(n+1);
    for(int i=0; i<m; i++){
        int v,u;
        cin >> v >> u;
        if(adj_list[v].count(u)){
            adj_list[v][u]++;
        } else {
            adj_list[v][u]=1;
        }
    }

    vector<int> min_dist (n+1,-1);
    vector<bool> visited (n+1,false);

    dfs(1,adj_list,min_dist,visited);
    cout << min_dist[1] << '\n';

}

int main()
{
    solve();
    return 0;
}
