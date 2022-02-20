#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    bool non_decreasing = true;
    for(int i=2;i<=n&&non_decreasing;i++){
        if(v[i]<v[i-1]){
            non_decreasing = false;
        }
    }
    if(non_decreasing){
        cout << 0 << '\n';
        return;
    }
    if(v[n-1]>v[n]||v[n]<0){
        cout << -1 << '\n';
        return;
    }
    cout << n-2 << '\n';
    for(int i=1; i<=n-2; i++){
        cout << i << " " << n-1 << " " << n << '\n';
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
