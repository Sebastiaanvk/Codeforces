#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b (m);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int index = 0;
    for(int i=m-1; i>=0; i--){
        if(index<n-b[i]){
            index = index+b[i];
        } else {
            index  = index - (n-b[i]);
        }
    }
    cout << a[index] << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
