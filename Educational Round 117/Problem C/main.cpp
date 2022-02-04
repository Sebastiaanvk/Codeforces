#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long k,x;
        cin >> k >> x;
        if(k==1){
            cout << 1 << endl;
        } else if( k*(k+1)/2 +(k-1)*k/2<x ){
            cout << 2*k-1 << endl;
        } else if( k*(k+1)/2<x ){
            long long y = x-k*(k+1)/2;
            long long rem = (k-1)*k/2-y;
            long double p = -0.5+sqrtl(2*rem+0.25);
            long long w = p;
            cout << k+(k-1)-w << endl;

        } else {
            long double n = -0.5+sqrtl(2*x+0.25);
            long long v = ceil(n);
            cout << v << endl;
        }
    }
    return 0;
}
