#include <iostream>
#include <bits/stdc++.h>
#define watch(x) cout << #x << ": " << x << '\n';

using namespace std;


bool solve(){
    int n;
    cin >> n;
    bool palindrome_found = false;
    set<string> st;
    set<string> st_triple_prefix;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(!palindrome_found){
            if( s.size()==1 || (s.size()==2&&s[0]==s[1]) || (s.size()==3&&s[0]==s[2]) ){
                palindrome_found = true;
            }
            if(s.size()==3){
                if(st.count( {s[2],s[1]} )||st.count({s[2],s[1],s[0]} ) ){
                    palindrome_found=true;
                }
                st_triple_prefix.insert(s.substr(0,2));
            }else {
                if( st.count( {s[1],s[0]} ) || st_triple_prefix.count( {s[1],s[0]} )){
                    palindrome_found=true;
                }
            }

            st.insert(s);
        }
    }
    if(palindrome_found) return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--) cout << (solve()?"YES\n":"NO\n");
    return 0;
}
