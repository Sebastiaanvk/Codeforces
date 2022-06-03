#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int odds = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2==1) odds++;
    }
    if(odds!=0){
        cout << n-odds << '\n';
    } else {
        int min_div = INT_MAX;
        for(int i=0;i <n; i++){
            int divs=0;
            int x = a[i];
            while(x%2==0){
                divs++;
                x/=2;
            }
            min_div = min(min_div,divs);
        }
        cout << min_div+n-1 << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
