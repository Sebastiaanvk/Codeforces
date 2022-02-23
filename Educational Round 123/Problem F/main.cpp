#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long P = 998244353;

map<pair<int,int>,long long> B;

long long get_b(int n, int k){
    if(B.count(){n,k}){
        return B[{n,k}];
    }


}

void solve(){
    int n,k;
    cin >> n >> k;
    long long answer=0;
    for(int l=1;l<=k;l++){
        answer = (answer+get_b(n,l));
    }

    cout << answer << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
