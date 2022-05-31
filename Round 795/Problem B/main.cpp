#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int i=0;
    while(i<n){
        if(i==n-1||v[i+1]!=v[i]){
            cout << -1 << '\n';
            return;
        }
        int j=i+1;
        while(j+1<n&&v[j+1]==v[i])
            j++;
        for(int k=i; k<j; k++){
            ans[k] = k+2;
        }
        ans[j] = i+1;
        i = j+1;
    }
    for(int k=0; k<n; k++){
        cout << ans[k] << " ";
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
