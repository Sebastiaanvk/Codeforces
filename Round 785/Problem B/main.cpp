#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int i=0;
    int j=1;
    map<char,int> contains;
    contains[s[i]]=1;
    while( contains.count(s[j])==0 ){
        contains[s[j]]=1;
        j++;
    }

    while(j<s.size()){
        if(s[j]!=s[i]){
            cout << "NO\n";
            return;
        }
        j++;
        i++;
    }
    cout << "YES\n";

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
