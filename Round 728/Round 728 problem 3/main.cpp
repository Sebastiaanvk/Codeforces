#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<long long> v;
        for(int j=0;j<n;j++){
            long long x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        long long sum_distances=0;
        long long price = 0;
        for( int j=1; j<n; j++){
            price += v[j]-v[j-1]-j*v[j]+sum_distances;

            sum_distances += v[j];
        }
        cout << price << endl;
    }
    return 0;
}
