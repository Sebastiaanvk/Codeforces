#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, c ,q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    long long current_pos = n;
    vector<long long> starts_intervals = {0};
    vector<long long> sources = {0};
    for(int i = 1; i<=c; i++){
        long long l,r;
        cin >> l >> r;
        l--;
        r--;
        starts_intervals.push_back(current_pos);
        sources.push_back(l);
        current_pos += r-l+1;
    }

    for(int i=0; i<q; i++){
        long long k;
        cin >> k;
        k--;
        while(k>=n){
            int int_min=0;
            while(!(int_min==c||(starts_intervals[int_min]<=k&&starts_intervals[int_min+1]>k))){
                int_min++;
            }
            k = (k-starts_intervals[int_min])+sources[int_min];
        }
        cout << s[k] << '\n';
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
