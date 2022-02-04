#include <iostream>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    for(long long i=0; i<t; i++){
        long long x,n;
        cin >> x >> n;
        long long shift=0;
        if(n%4==1){
            shift=n;
        } else if(n%4==2){
            shift=-1;
        } else if(n%4==3){
            shift=-n-1;
        }
        if(x%2){
            cout << x+shift << endl;
        } else {
            cout << x-shift << endl;
        }
    }

    return 0;
}
