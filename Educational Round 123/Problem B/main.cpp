#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_perms(vector<int>& prefix, int n){
    if(n==1){
        for(auto x:prefix) cout << x << " ";
        cout << "1" << '\n';
        return;
    }
    prefix.push_back(n);
    print_perms(prefix,n-1);
    prefix.pop_back();
    for(auto x:prefix) cout << x << " ";
    cout << "1 " << n << " ";
    for(int i=2;i<n;i++){
        cout << i << " ";
    }
    cout << '\n';
}

void solve(){
    int n;
    cin >> n;
    vector<int> prefix;
    print_perms(prefix, n);


}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
