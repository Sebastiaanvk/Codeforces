#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n,k;
    cin >> n >> k;
    vector<long long> a (n);
    for(int i=0; i<n; i++) cin >> a[i];
    long long nr_mushrooms = 0;
    if(k<n){
        long long max_sum = 0;
        long long current_sum = 0;
        for( int i=0;i<k; i++){
            current_sum += a[i];
        }
        max_sum = current_sum;
        for( int j=k; j<n; j++){
            current_sum = current_sum -a[j-k]+a[j];
            max_sum = max(max_sum,current_sum);
        }
        nr_mushrooms = max_sum + ((k-1)*k)/2;
    } else {
        long long sum = 0;
        for(int i=0;i<n; i++) sum += a[i];
        nr_mushrooms = sum + n*k - (n*(n+1))/2;
    }
    cout << nr_mushrooms << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
