#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int left=1;
    int right=n;
    while(right>left){
        int m = (right+left)/2;
        cout << "? " << left << " " << m << '\n';
        cout.flush();
        int nr_inside = 0;
        for(int i=left; i<=m; i++){
            int x;
            cin >> x;
            if(x>=left&&x<=m){
                nr_inside++;
            }
        }
        if(nr_inside%2==1){
            right=m;
        } else {
            left = m+1;
        }
    }
    cout << "! " << left << '\n';
    cout.flush();

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
