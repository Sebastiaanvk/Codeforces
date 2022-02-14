#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int nr_components = 0;
    int maxi = 0;
    for(int i=1;i<=n; i++){
        int x;
        cin >> x;
        maxi= max(x,maxi);
        if(maxi==i){
            nr_components++;
        }
    }
    cout << nr_components << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
