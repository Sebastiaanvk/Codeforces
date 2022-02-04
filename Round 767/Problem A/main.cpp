#include <iostream>
#include <bits/stdc++.h>
#define watch(x) cout << #x << ": " << x << '\n';

using namespace std;

struct ER{
    int ram_needed;
    int ram_gained;
};
bool operator<(const ER& er1, const ER& er2){
    return er1.ram_needed<er2.ram_needed;
}
bool operator==(const ER& er1, const ER& er2){
    return er1.ram_needed==er2.ram_needed&&er1.ram_gained==er2.ram_gained;
}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<ER> v (n);
    for(int i=0; i<n; i++){
        cin >> v[i].ram_needed;
    }
    for(int i=0; i<n; i++){
        cin >> v[i].ram_gained;
    }
    sort(v.begin(),v.end());
    int i=0;
    while(i<n&&v[i].ram_needed<=k){
        k+=v[i].ram_gained;
        i++;
    }
    cout << k << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
