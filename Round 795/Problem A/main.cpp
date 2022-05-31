#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int odds = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x%2!=0){
            odds++;
        }
    }
    cout << min(odds, n-odds) << '\n';

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
