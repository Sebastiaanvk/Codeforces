#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<list<int>> adj_list(n+1);
vector<int> h(n+1);

struct Price_and_max{
    int price;
    int maxi;
};

Price_and_max try_tree(int start, int source){
    if(adj_list[start].size()==1){
        return {h[start],h[start]};
    }
    int total_cost=0;
    int highest_h = 0;
    for( auto x:adj_list[start]){
        if(x!=source){
            Price_and_max p = try_tree(x,start);
            total_cost += p.price;

        }
    }
    return {};
}

void solve(){
    int n;
    cin >> n;

    int max_h=0;
    int begi;
    for(int i=1; i<=n; i++){
        cin >> h[i];
        if(h[i]>max_h){
            max_h = h[i];
            max_i = i;
        }
    }

    for(int i=1;i<n;i++){
        int v,u;
        cin >> v >> u;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    if(n==2){
        cout << 2*max_h << '\n';
        return ;
    }

    if(adj_list[begi].size()==1){
        begi = adj_list[begi][0];
    }

    long long total_costs = 0;
    Price_and_max p = try_tree(begi,-1);
    cout << p.price << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
