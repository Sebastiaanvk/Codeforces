#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i=0; i<k ; i++){
        long long n,x,t;
        cin >> n >> x >> t;
        if(t/x>n-1){
            cout << n*(n-1)/2;
        } else {
            long long m = t/x;
            cout << n*m-m*(m+1)/2;
        }
        cout << endl;
    }
    return 0;
}
