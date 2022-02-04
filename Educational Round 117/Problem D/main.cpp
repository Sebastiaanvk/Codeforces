#include <iostream>

using namespace std;

bool possible_make_x(long long a, long long b, long long x){
    if(a>b){
        swap(a,b);
    }
    if(b==x||a==x){
        return true;
    }
    while(a!=0&&b!=0&&b>=x&&b!=a){
        if( (x>=a && x<=b &&(x%a==b%a) )||x==a ){
            return true;
        }
        b = b%a;
        swap(a,b);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long a,b,x;
        cin >> a >> b >> x;
        if(possible_make_x(a,b,x)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
