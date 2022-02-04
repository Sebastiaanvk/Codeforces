#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long x, long long y){
    if(x>y) swap(x,y);
    long long r=y%x;
    while(r!=0){
        y=x;
        x=r;
        r=y%x;
    }
    return x;
}

long long calc_max( const vector<long long>& gcds ){
    if(gcds.size()==0){
        return 0;
    }

    long long max_sum=0;

    for( int i=0; i<gcds.size(); i++){
        vector<long long> new_gcds;
        for(int j=0; j<gcds.size(); j++){
            if(i!=j){
                long long g = gcd(gcds[i],gcds[j]);
                if(g!=0){
                    new_gcds.push_back(g);
                }
            }
            long long c = calc_max(new_gcds);
            if( gcds[i]+c+gcds.size()-1-new_gcds.size()>max_sum ){
                max_sum = gcds[i]+c+gcds.size()-1-new_gcds.size();
            }
        }
    }
    return max_sum;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(), greater<long long>());

    long long max_sum=0;

    for(int i=0; i<n ; i++){
        vector<long long> gcds;
        for(int j=0; j<n; j++){
            if(i!=j){
                long long g = gcd(v[i],v[j]);
                if(g!=1){
                    gcds.push_back(g);
                }

            }
        }
        long long c = calc_max(gcds);
        if( v[i]+c+n-1-gcds.size()>max_sum ){
            max_sum = v[i]+c+n-1-gcds.size();
        }
    }
    cout << max_sum << endl;


    return 0;
}
