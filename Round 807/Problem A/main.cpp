#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> v(2*n);
    for(int i=0; i<2*n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    bool possible = true;
    for(int i=0; i<n; i++){
        if(v[i+n]-v[i]<x){
            possible = false;
        }
    }
    if(possible){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
