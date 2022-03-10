#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n>19){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int p =1;
    for(int i=1;i<=n;i++){
        cout << p << " ";
        p *= 3;

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
