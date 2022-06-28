#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    bool only_zeros = true;
    for(int i=0; i<n ;i++){
        cin >> v[i];
        if(v[i]!=0)
            only_zeros=false;
    }
    if(only_zeros){
        cout << "YES\n";
    } else if(n>4){
        cout << "NO\n";
    } else if(n==4){
        long long sum = v[0]+v[1]+v[2]+v[3];
        for(int i=0; i<4; i++){
            int left = sum - v[i];
            bool in = false;
            for(int i=0;i<4; i++){
                if(v[i]==left) in=true;

            }
            if(in) cout << "YES\n";
            else cout << "NO\n";
        }
    } else {
        long long sum = v[0]+v[1]+v[2];
        bool in = false;
        for(int i=0; i<n; i++){
            if(sum == v[i])
                in = true;
        }
        if(in) cout << "YES\n";
            else cout << "NO\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
