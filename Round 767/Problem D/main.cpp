#include <iostream>
#include <bits/stdc++.h>
#define watch(x) cout << #x << ": " << x << '\n';

using namespace std;

bool solve(){
    int n;
    cin >> n;
    bool palindrome_found = false;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        if( v[i].size()==1 || (v[i].size()==2&&v[i][0]==v[i][1]) || (v[i].size()==3&&v[i][0]==v[i][2]) ){
            palindrome_found = true;
        }
    }
    if(palindrome_found) return true;

    for(int i=0;i<n; i++){
        for(int j=i+1;j<n;j++){
            if(v[i].size()==2){
                if(v[j].size()==2){
                    if(v[i][0]==v[j][1]&&v[i][1]==v[j][0]) return true;
                } else {
                    if(v[i][0]==v[j][2]&&v[i][1]==v[j][1]) return true;
                }
            } else {
                if(v[j].size()==2){
                    if(v[i][0]==v[j][1]&&v[i][1]==v[j][0]) return true;
                } else {
                    if(v[i][0]==v[j][2]&&v[i][1]==v[j][1]&&v[i][2]==v[j][0]) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--) cout << (solve()?"YES\n":"NO\n");
    return 0;
}
