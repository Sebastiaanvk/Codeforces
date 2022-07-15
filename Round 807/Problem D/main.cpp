#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s,t;
    cin >> s;
    cin >> t;
    if(s[0]!=t[0]||s[n-1]!=t[n-1]){
        cout << -1 << '\n';
        return;
    }
    long long s_left = 0;
    long long t_left = 0;
    long long nr_moves = 0;
    while(s_left<n){
        while(s_left<n && s[s_left]=='0'){
            s_left++;
        }
        long long s_right = s_left;
        while(s_right<n&&s[s_right]=='1') s_right++;

        while(t_left<n && t[t_left]=='0'){
            t_left++;
        }
        long long t_right = t_left;
        while(t_right<n&&t[t_right]=='1') t_right++;

        if(s_left==n||t_left==n){
            if(s_left!=n||t_left!=n){
                cout << -1 << '\n';
                return;
            }
        }
        if(s_right==n||t_right==n){
            if(s_right!=n||t_right!=n){
                cout << -1 << '\n';
                return;
            }
        }
        nr_moves += abs(s_left-t_left)+abs(s_right-t_right);
        s_left = s_right;
        t_left = t_right;
    }
    cout << nr_moves << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
