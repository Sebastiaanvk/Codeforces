#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(){

}

void solve(){
    int n;
    cin >> n;
    map<int,pair<int,int>> outgoing;
    vector<pair<int,int>> v;
    bool possible = true;

    for(int i=0; i<n-1; i++){
        int v1,v2;
        cin >> v1 >> v2;
        v.push_back({v1,v2});
        if(outgoing.count(v1)){
            if( outgoing[v1].second!=0 ){
                possible = false;
            } else {
                outgoing[v1] = {outgoing[v1].first,v2};
            }
        } else {
            outgoing[v1] = {v2,0};
        }

        if(outgoing.count(v2)){
            if( outgoing[v2].second!=0 ){
                possible = false;
            } else {
                outgoing[v2] = {outgoing[v2].first,v1};
            }
        } else {
            outgoing[v2] = {v1,0};
        }
    }


    if(!possible){
        cout << "-1" << endl;
        return;
    }

    int starting_v;
    for(auto p:outgoing){
        if(p.second.second==0){
            starting_v=p.first;
        }
    }

    map<pair<int,int>,int> edge_weight;
    int last_v = starting_v;
    int current_v = outgoing[starting_v].first;
    edge_weight[{last_v,current_v}] = 2;
    edge_weight[{current_v,last_v}] = 2;
    int next_value=5;
    while(outgoing[current_v].second!=0){
        if( edge_weight.count({outgoing[current_v].first,current_v}) ){
            edge_weight[{outgoing[current_v].second,current_v}] = next_value;
            edge_weight[{current_v,outgoing[current_v].second}] = next_value;
            next_value = (next_value==2?5:2);
            current_v=outgoing[current_v].second;
        } else {
            edge_weight[{outgoing[current_v].first,current_v}] = next_value;
            edge_weight[{current_v,outgoing[current_v].first}] = next_value;
            next_value = (next_value==2?5:2);
            current_v=outgoing[current_v].first;
        }
    }

    for(int i=0; i<v.size();i++){
        cout << edge_weight[v[i]] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
