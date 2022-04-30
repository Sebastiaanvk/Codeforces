#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> v(n,0);
    for(int i=0; i<n; i++) cin >> v[i];
    long long min_moves = LLONG_MAX;

    for(int i=0; i<n; i++){
        long long moves = 0;
        int left= i-1;
        long long last = 0;
        while(left>=0){
            long long x = v[left];
            long long moves_x = (last / x)+1;
            moves += moves_x;
            last = moves_x*x;
            left--;
        }

        int right= i+1;
        last = 0;
        while(right<n){
            long long x = v[right];
            long long moves_x = (last / x)+1;
            moves += moves_x;
            last = moves_x*x;
            right++;
        }
        min_moves = min(min_moves, moves);
    }
    cout << min_moves << endl;
}

int main()
{
    solve();
    return 0;
}
