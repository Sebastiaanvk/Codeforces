#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    int first_one = -1;
    int last_one;
    int nr_ones = 0;
    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        if(x=='1'){
            last_one=i;
            nr_ones++;
            if(first_one==-1){
                first_one = i;
            }
        }
    }
    if(nr_ones==0){
        cout << 0 << '\n';
    } else if(nr_ones==1){
        if(n-1-last_one<=k){
            cout << 1 << '\n';
        } else if(first_one<=k){
            cout << 10 << '\n';
        } else {
            cout << 11 << '\n';
        }
    } else {
        int res = 11*nr_ones;
        if(n-1-last_one<=k){
            res -= 10;
            k -= n-1-last_one;
        }
        if(first_one<=k){
            res -= 1;
        }
        cout << res << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
