#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x;
    cin >> x;
    if(x==1){
        cout << 3 << '\n';
        return;
    }
    int y=1;
    int  c = x;
    while(c%2==0){
        c/=2;
        y *= 2;
    }
    if(c/2==0){
        cout << y+1 << '\n';
    } else {
        cout << y << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
