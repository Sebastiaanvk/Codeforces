#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x!=0){
            sum += i*(n+1-i);
        } else {
            sum += 2*i*(n+1-i);
        }
    }
    cout << sum << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
