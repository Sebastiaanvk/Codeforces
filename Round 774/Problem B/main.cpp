#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sum=0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(),v.end());
    long long first_half = 0;
    if(n%2==1){
        for(int i=0; i<=n/2; i++){
            first_half += v[i];
        }
        if(first_half<sum-first_half){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    } else {
        for(int i=0; i<n/2; i++){
            first_half += v[i];
        }
        if(first_half<sum-first_half-v[n/2]){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
