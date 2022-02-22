#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long P = 998244353;

void solve(){
    long long n,m,k,q;
    cin >> n >> m >> k >> q;

    vector<int> xs;
    vector<int> ys;
    for(int i=0;i<q; i++){
        int x;
        int y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    vector<bool> rows(n+1,true);
    vector<bool> cols(m+1,true);
    long long total = 1;

    int cols_left=m;
    int rows_left=n;

    for(int i=q-1;i>=0&&cols_left!=0&&rows_left!=0;i--){
        int x = xs[i];
        int y = ys[i];
        if(rows[x]||cols[y]){
            total = (total*k)%P;
            if(rows[x]){
                rows[x]=false;
                rows_left--;
            }
            if(cols[y]){
                cols[y]=false;
                cols_left--;
            }
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
