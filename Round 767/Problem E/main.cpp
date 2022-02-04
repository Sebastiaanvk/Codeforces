#include <iostream>
#include <bits/stdc++.h>
#define watch(x) cout << #x << ": " << x << '\n';

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> field(n,vector<int>(n));
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin >> field[y][x];
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
