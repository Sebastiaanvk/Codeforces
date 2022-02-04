#include <iostream>

using namespace std;

const long long P = 1000000007;

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


int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        long long n;
        cin >> n;
        long long left_over=n;
        long long total_divisor=1;
        long long current_divisor=2;
        long long sum=0;
        while(left_over>0){
            long long k = current_divisor/gcd(current_divisor,total_divisor);
            total_divisor *= k;
            long long multiples = left_over/k;
            long long extra = ((left_over-multiples)*current_divisor )%P;
            sum = (sum+extra)%P;
            left_over = multiples;
            current_divisor++;
        }
        cout << sum << endl;
    }
    return 0;
}
