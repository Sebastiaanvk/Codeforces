#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int smallest_loc = n-1;
    vector<int> v(n);
    bool sorted = true;
    int unsorted_start=n;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(!sorted && v[i]==unsorted_start+1){
            smallest_loc= i;
        }
        if(sorted &&v[i]!=i+1){
            sorted=false;
            unsorted_start = i;
        }

    }
    for(int i=0;i<unsorted_start; i++) cout << v[i] << ' ';

    for(int i=unsorted_start;i<=smallest_loc;i++){
        cout << v[smallest_loc+unsorted_start-i] << ' ';
    }
    for(int i=smallest_loc+1; i<n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
