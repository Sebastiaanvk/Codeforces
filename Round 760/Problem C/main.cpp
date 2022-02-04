#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long x, long long y){
    if(x>y) swap(x,y);
    long long r = y%x;
    while(r!=0){
        y=x;
        x=r;
        r=y%x;
    }
    return x;
}

bool doesnt_divide_others(vector<long long>& v, long long g, bool skip){
    int ind = 0;
    if(skip) ind = 1;
    while( ind<v.size() ){
        if(v[ind]%g==0) return false;
        ind += 2;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for( int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<long long > v;
        for( int j=0; j<n; j++){
            long long x;
            cin >> x;
            v. push_back(x);
        }

        long long gcd1 = v[0];
        long long gcd2 = v[1];


        for(int j=2; j<n; j++){
            if(j%2==0){
                gcd1 = gcd(gcd1, v[j]);
            } else {
                gcd2 = gcd(gcd2, v[j]);
            }
        }
        if( doesnt_divide_others(v, gcd1, true) ) cout << gcd1 << endl;
        else if( doesnt_divide_others(v, gcd2, false) ) cout << gcd2 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
