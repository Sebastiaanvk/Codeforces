#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void solve(){
    string s;
    cin >> s;
    bool keys[3] = {false,false,false};
    for(char c:s){
        if(c>='A'&& c<='Z'){
            if( (c=='R'&&!keys[0])||(c=='G'&&!keys[1])||(c=='B'&&!keys[2]) ){
                cout << "NO\n";
                return;
            }
        } else if(c=='r'){
            keys[0]=true;
        } else if(c=='g'){
            keys[1]=true;
        } else if(c=='b'){
            keys[2]=true;
        }
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
