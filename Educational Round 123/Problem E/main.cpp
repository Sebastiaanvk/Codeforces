#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    int down_end=0;
    int right_end=0;
    for(char c:s){
        if(c=='D')  down_end++;
        else        right_end++;
    }
    if(down_end==0||right_end==0){
        cout << n << '\n';
        return;
    }


    int current_down = 0;
    int current_right = 0;

    long long total = n*n;

    int i=0;
    while(s[i]==s[0]){
        total -= n-1;
        if(s[0]=='D'){
            current_down++;
        } else {
            current_right++;
        }
        i++;
    }

    for(; i<s.size(); i++){
        char c = s[i];
        if(c=='D'){
            total -= right_end-current_right;
            current_down++;
        } else {
            total -= down_end - current_down;
            current_right++;
        }
    }


    cout << total << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
