#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int sum = 0;
    for(int i=0; i<s.size(); i++){
        sum += (s[i]-'a')+1;
    }
    if(s.size()==1){
        cout << "Bob " << sum << '\n';
    } else if(s.size()%2==0){
        cout << "Alice " << sum << '\n';
    } else {
        cout << "Alice " << max(sum-2*(s[0]-'a'+1),sum-2*(s[s.size()-1] -'a'+1) ) << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
