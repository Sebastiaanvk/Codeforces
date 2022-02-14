#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int highest_odd = 0;
    int highest_even = 0;
    bool possible = true;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(possible){
            if(x%2==0){
                if(highest_even>x){
                    possible = false;
                }
                highest_even = x;
            } else{
                if(highest_odd>x){
                    possible = false;
                }
                highest_odd = x;
            }
        }
    }
    cout << (possible?"Yes\n":"No\n");
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
