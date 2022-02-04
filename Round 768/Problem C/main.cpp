#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    if(k==0){
        for(int x=0;x<n/2;x++){
            cout << x << " " << n-1-x << '\n';
        }
    }
    else if(k!=n-1){
        cout << n-1-k << " " << 0 << '\n';
        cout << k << " " << n-1 << '\n';
        for(int x=1;x<n/2;x++){
            if(x!=k&&x!=n-1-k){
                cout << x << " " << n-1-x << '\n';
            }
        }
    } else {
        if(n==4){
            cout << -1 << '\n';
            return;
        }
        cout << n-1 << " " << n-2 << '\n';
        cout << 1 << " " << n/2+1 << '\n';
        cout << 0 << " " << n/2-2 << '\n';
        cout << n/2-1 << " " << n/2 << '\n';
        for(int x=2;x<n/2-2;x++){
            cout << x << " " << n-1-x << '\n';
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
