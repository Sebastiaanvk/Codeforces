#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int goal = v[n-1];
    int left_pos_goal = n-1;
    while(left_pos_goal>0&&v[left_pos_goal-1]==goal){
            left_pos_goal--;
    }
    int moves=0;
    while(left_pos_goal>0){
        left_pos_goal -= n-left_pos_goal;

        while(left_pos_goal>0&&v[left_pos_goal-1]==goal){
            left_pos_goal--;
        }
        moves++;
    }

    cout << moves << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
