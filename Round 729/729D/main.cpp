#include <iostream>
#include <vector>

using namespace std;

const long long P = 998244353;

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

void times_fraction(long long& p1, long long& q1, const long long& p2, const long long& q2){
    long long p = p1*p2;
    long long q = q1*q2;
    long long g = gcd(p,q);
    p/=g;
    q/=g;
    p1=p;
    q1=q;
}

void add_fraction(long long& p1, long long& q1, const long long& p2, const long long& q2){
    long long g = gcd(q1,q2);
    long long p = p1*q2/g+p2*q1/g;
    long long q = q1*q2/g;
    p1=p;
    q1=q;
}

long long power(long long b, long long n){
    if(n==0){
        return 1;
    }
    return b*power(b,n-1);
}

int main()
{
    int n;
    cin >> n;
    vector<long long> numbers;
    vector<long long> numerators;
    vector<long long> denominators;

    for( int k=0; k<n; k++){
        char c;
        cin >> c;
        if(c=='+'){
            long long x;
            cin >> x;
            numbers.push_back(x);
            numerators.push_back(1);
            denominators.push_back(2);
        } else {
            for(int i=0;i<numbers.size(); i++){
                long long p=1;
                long long q=2;
                for( int j=0; j<i; j++){
                    if(numbers[j]<numbers[i]){
                        times_fraction(p,q,numerators[j],denominators[j]);
                    }
                }
                times_fraction(p,q,denominators[i]-numerators[i],denominators[i]);
                add_fraction(numerators[i],denominators[i],p,q);
            }
        }

    }
    long long total=0;
    for(int i=0;i<numbers.size(); i++){
        long long v = (power(2,numbers.size())*numbers[i]*numerators[i])%P;
        total += v/=denominators[i];
    }
    cout << total << endl;

    return 0;
}
