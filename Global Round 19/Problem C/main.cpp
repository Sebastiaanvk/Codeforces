#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long moves=0;
    int f;
    cin >> f;
    bool all_ones = true;
    if(n==3){
        int x;
        cin >> x;
        cout << (x%2==0?x/2:-1) <<'\n';
        cin >> f;
        return;
    }

    for(int i=2;i<n;i++){
        int x;
        cin >> x;
        if(x!=1) all_ones=false;
        moves += (x+1)/2;
    }
    cin >> f;

    if(all_ones){
        cout << -1 << '\n';
    } else {
        cout << moves << '\n';
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
