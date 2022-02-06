#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    if(n%2==1&&k==1){
        cout << "YES\n";
        for(int i=1; i<=n; i++){
            cout << i << '\n';
        }
        return;
    } else if(n%2==1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << '\n';
    for(int i=0; i<n; i+=2){
        for(int j=1; j<=k; j++){
            cout << 2*j+k*i << " ";
        }
        cout << '\n';
        for(int j=1; j<=k; j++){
            cout << 2*j-1 +k*i << " ";
        }
        cout << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
