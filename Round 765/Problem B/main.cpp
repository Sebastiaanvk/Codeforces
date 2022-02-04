#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int min_dist=INT_MAX;
    unordered_map<int,int> rp;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(rp.count(x)){
            min_dist = min(min_dist,i-rp[x]);
        }
        rp[x]=i;
    }

    cout << ( (min_dist==INT_MAX)?-1:n-min_dist) << "\n";

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
