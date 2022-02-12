#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int last_x;
    cin >> last_x;
    bool sorted=true;
    for(int i=1; i<n; i++) {
        int x;
        cin >> x;

        if(x<last_x){
            sorted = false;
        }
        last_x = x;
    }
    cout << (sorted?"NO\n":"YES\n");

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
