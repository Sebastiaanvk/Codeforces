#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> v;
    long long a;
    for(long long i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }
    sort( v.begin(), v.end() );
    vector<long long> diffs;
    long long gaps=0;
    for( long long i=0; i<n-1;i++){
        if( v[i+1]-v[i]>x ){
            diffs.push_back(v[i+1]-v[i]);
            gaps++;
        }
    }
    sort(diffs.begin(),diffs.end());
    for(long long i=0; i<diffs.size()&&k>=(diffs[i]-1)/x ;i++){
        gaps--;
        k -= (diffs[i]-1)/x;
    }
    cout << gaps+1;

    return 0;
}
