#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int min_digit=10;
    if(n<10){
        cout << n << '\n';
            return;
    }else if(n<100){
        cout << (n%10) << '\n';
        return;
    }
    while(n!=0){
        min_digit = min( min_digit, n%10);
        n /= 10;
    }
    cout << min_digit << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
