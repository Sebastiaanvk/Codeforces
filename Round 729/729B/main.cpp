#include <iostream>

using namespace std;
/*
bool in_set(long long n, const long long& a, const long long& b){
    if(n%b==1){
        return true;
    }
    if(n<1){
        return false;
    }
    if(a>1 && n%a==0 && in_set(n/a,a,b)){
        return true;
    }
    if(b>0 && in_set(n-b,a,b)){
        return true;
    }
    return false;
}*/

bool in_set(const long long& n, const long long& a, const long long& b){
    if(a==1){
        return (n-1)%b==0;
    }
    long long x=1;
    while(x<=n){
        if((n-x)%b==0){
            return true;
        }
        x *= a;

    }
    return false;
}

int main()
{
    long long t,n,a,b;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> a >> b;
        if(in_set(n,a,b)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}
