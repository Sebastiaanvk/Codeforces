#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int compare(const vector<int>& a, const vector<int>& b, int i, int j){
    if(a[i]==a[j]){
        if(b[j]<b[i])
            return 1;
        else
            return -1;
    } else if(a[i]<a[j]){
        if(b[i]>b[j])
            return 0;
        else
            return -1;
    } else {
        if(b[i]<b[j])
            return 0;
        else
            return 1;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for( int i=0; i<n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i=0; i<n; i++) cin >> b[i];

    vector<pair<int,int>> swaps;

    for( int i=0; i<n ;i++){
        int min_j = i;
        for( int j=min_j+1; j<n; j++){
            int res = compare(a,b,min_j, j);
            if(res==0){
                cout << -1 << '\n';
                return;
            }
            if(res==1){
                min_j=j;
            }
        }
        if(min_j!=i){
            swaps.push_back({min_j,i});
            swap(a[min_j],a[i]);
            swap(b[min_j],b[i]);
        }

    }

    cout << swaps.size() << '\n';
    for(int i=0; i< swaps.size(); i++){
        cout << swaps[i].first+1 << " " << swaps[i].second+1 << '\n';
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
