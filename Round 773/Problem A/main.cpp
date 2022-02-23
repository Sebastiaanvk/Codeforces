#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector<int> already_used(n,false);

    int i=0;
    int j=1;

    int added = 0;

    while(i<n){
        while(j<n&&v[j]<x*v[i]){
            j++;
        }
        while(j<n&&already_used[j]){
            j++;
        }
        if( j<n && v[j]==x*v[i] ){
            already_used[j]=true;
        } else {
            added++;
        }
        already_used[i]=true;

        while(i<n&&already_used[i]){
            i++;
        }
    }

    cout << added << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
