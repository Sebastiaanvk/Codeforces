#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,l,r,k;
        cin >> n >> l >> r >> k;
        vector<int> bars;
        int x;
        for(int j=0; j<n; j++){
            cin >> x;
            bars.push_back(x);
        }
        sort(bars.begin(), bars.end());
        int bars_bought=0;
        int pos=0;
        while(pos<bars.size()&&bars[pos]<=k&&bars[pos]<=r){
            if(bars[pos]>=l){
                bars_bought++;
                k -= bars[pos];
            }
            pos++;
        }
        cout << bars_bought << endl;

    }
    return 0;
}
