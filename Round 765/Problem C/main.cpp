#include <iostream>
#include <vector>
using namespace std;

void solve(){
    long long n, l, k;
    cin >> n >> l >> k;
    vector<vector<long long>> v(n+1,vector<long long>(k+1,INT_MAX/2));
    for(int i=0; i<=k; i++){
        v[n][i]=0;
    }
    vector<long long> locations(n+1);
    vector<long long> speeds(n);
    for(int i=0; i<n; i++){
        cin >> locations[i];
    }
    locations[n] = l;
    for(int i=0; i<n; i++){
        cin >> speeds[i];
    }

    for(int i=n-1; i>=0; i--){
        for(int b=0;b<=k&&b<=n-i-1;b++){
            for(int j=i+1;j<=n&&b+i+1-j>=0;j++){
                v[i][b] = min( v[i][b],v[j][b+i+1-j]+(locations[j]-locations[i])*speeds[i] );
            }
        }
    }

    long long mi = INT_MAX/2;
    for(auto x:v[0]) mi = min(mi,x);
    cout << mi << "\n";

}

int main()
{
    solve();
    return 0;
}
