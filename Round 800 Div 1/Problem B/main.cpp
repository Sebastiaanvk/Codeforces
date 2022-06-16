#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int parent;
    list<int> child;
    long long l;
    long long r;
    long long min_moves;
    long long max_value;
};

void find_min_moves(int index, vector<Node>& nodes){
    long long max_sum = 0;
    long long nr_moves = 0;
    if(nodes[index].child.size()!=0){
        for( auto c : nodes[index].child ){
            find_min_moves(c,nodes);
            nr_moves += nodes[c].min_moves;
            max_sum += nodes[c].max_value;
        }
        if( max_sum >= nodes[index].l){
            nodes[index].min_moves = nr_moves;
            nodes[index].max_value = min(max_sum,nodes[index].r);
        } else {
            nodes[index].min_moves = nr_moves+1;
            nodes[index].max_value = nodes[index].r;
        }
    } else {
        nodes[index].min_moves = 1;
        nodes[index].max_value = nodes[index].r;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for(int i=1; i<n; i++){
        cin >> nodes[i].parent;
        (nodes[nodes[i].parent-1].child).push_back(i);
    }
    for(int i=0; i<n; i++){
        cin >> nodes[i].l;
        cin >> nodes[i].r;
    }
    find_min_moves(0,nodes);
    cout << nodes[0].min_moves <<  '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
