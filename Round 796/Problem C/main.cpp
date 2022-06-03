#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bool> letter_removed(26,false);
    for(int i=0; i<2*n; i++){
        string s;
        cin >> s;
        for(char c:s){
            letter_removed[c-'a'] = !letter_removed[c-'a'];
        }

    }
    string s_end;
    cin >> s_end;
    for(char c:s_end){
        letter_removed[c-'a'] = !letter_removed[c-'a'];
    }
    for(int i=0; i<26; i++){
        if(letter_removed[i]){
            char c = 'a'+i;
            cout << c << '\n';
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
