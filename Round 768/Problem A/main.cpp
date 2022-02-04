#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    int abs_max=0;
    for(int i=0; i<n;i++){
        int x;
        cin >> x;
        abs_max = max(abs_max,x);
        a.push_back(x);
    }

    int smaller_max=0;
    for(int i=0; i<n;i++){
        int x;
        cin >> x;
        abs_max = max(abs_max,x);
        if(x<a[i]){
            smaller_max = max(smaller_max,x);
        } else {
            smaller_max = max(smaller_max,a[i]);
        }
    }

    cout << smaller_max*abs_max << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
