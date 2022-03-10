#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long mini(long long x, long long y){
    if(x<y)return x;
    return y;
}

void solve(){
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    long long m=abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
    m = mini(m,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));

    vector<long long> v(4,LLONG_MAX);

    for(int i=0; i<n; i++){
        v[0] = mini(v[0],abs(a[0]-b[i]));
        v[1] = mini(v[1],abs(a[n-1]-b[i]));
        v[2] = mini(v[2],abs(a[i]-b[0]));
        v[3] = mini(v[3],abs(a[i]-b[n-1]));
    }
    m = mini(m,v[0]+v[1]+v[2]+v[3]);
    m = mini(m,abs(a[0]-b[0])+v[1]+v[3] );

     m = mini(m,abs(a[0]-b[n-1])+v[1]+v[2] );

     m = mini(m,abs(a[n-1]-b[0])+v[0]+v[3] );

    m = mini(m,abs(a[n-1]-b[n-1])+v[0]+v[2] );


    cout << m << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
