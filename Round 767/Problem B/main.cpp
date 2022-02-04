#include <iostream>
#include <bits/stdc++.h>
#define watch(x) cout << #x << ": " << x << '\n';

using namespace std;

bool solve(){
    int l,r,k;
    cin >> l >> r >> k;
    int n = r-l+1;
    if(n==1) return l!=1;

    if(n%2==0||l%2==0){
        return k>=n/2;
    }else {
        return k>=(n+1)/2;
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) cout << (solve()?"YES\n":"NO\n");
    return 0;
}
