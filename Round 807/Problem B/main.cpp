#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    long long nr_moves = 0;
    for(int i=0; i<n-1; i++){
        nr_moves += v[i];
    }
    bool dust_found = false;
    for(int i=0; i<n-1; i++){
        if(v[i]>0) dust_found = true;
        else if(v[i]==0&& dust_found){
            nr_moves++;
        }
    }
    cout << nr_moves << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
