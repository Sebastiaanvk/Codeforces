#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}

void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k==0){
        cout << 1 << '\n';
        return;
    }
    cout << (is_palindrome(s)?1:2) << '\n';
}

int main()
{
    vector<int> v;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
