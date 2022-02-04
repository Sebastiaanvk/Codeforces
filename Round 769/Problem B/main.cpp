#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int p=1;
    while( (n-1)/p>1) p *= 2;
    for(int i=1;i<p;i++){
        cout << i << " ";
    }
    cout << 0 << " ";
    cout << p << " ";
    for(int i=p+1;i<n;i++){
        cout << i << " ";
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
