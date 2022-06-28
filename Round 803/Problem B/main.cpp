#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<long long> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(k==1){
        cout << (n-1)/2 << '\n';
    } else {
        int nr_tall = 0;
        for( int i=1; i<n-1; i++){
            long long sum = v[i-1]+v[i+1];
            if(v[i]>sum) nr_tall++;
        }
        cout << nr_tall << '\n';

    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
