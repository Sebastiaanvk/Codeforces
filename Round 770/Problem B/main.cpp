#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n,x,y;
    cin >> n >> x >> y;
    bool swish = false;
    for(int i=1; i<=n; i++){
        long long x;
        cin >> x;
        if(x%2==1){
            swish = !swish;
        }
    }
    if( (x%2==y%2&& !swish)||(x%2!=y%2&&swish) ){
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
