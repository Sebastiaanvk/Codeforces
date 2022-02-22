#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> starting_array(n);
    for(int i=0; i<n; i++) cin >> starting_array[i];

    vector<long long> max_that_size(n+1,0);
    for( int width=1; width<=n; width++ ){
        long long current_sum = 0;
        for(int i=0;i<width;i++){
            current_sum += starting_array[i];
        }
        max_that_size[width] = current_sum;
        for( int i=width; i<n; i++){
            current_sum += starting_array[i]-starting_array[i-width];
            max_that_size[width] = max(max_that_size[width],current_sum);
        }
    }
    long long ma=max_that_size[n];
    vector<long long> max_that_size_or_bigger(n+1,0);
    for(int width=n; width>=0; width--){
        ma = max(max_that_size[width],ma);
        max_that_size_or_bigger[width] = ma;

    }

    long long last_max=0;
    for(int k=0; k<=n; k++){
        long long new_max = max_that_size_or_bigger[k]+k*x;
        last_max = max(last_max,new_max);
        cout << last_max << ' ';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
