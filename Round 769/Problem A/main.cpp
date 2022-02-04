#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<char> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << (n==1||(n==2&&v[0]!=v[1])? "YES\n":"NO\n" );

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
