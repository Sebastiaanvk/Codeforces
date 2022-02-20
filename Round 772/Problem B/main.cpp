#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int m=0;
    for(int i=2; i<n-1; i++){
        if(v[i-2]<v[i-1]&&v[i]<v[i-1]){
            v[i] = max(v[i-1],v[i+1]);
            m++;
        }
    }
    if(v[n-2]>v[n-3]&&v[n-2]>v[n-1]){
        v[n-1]=v[n-2];
        m++;
    }
    cout << m << '\n';
    for(auto x:v) cout << x << ' ';
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
