#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        if(n%2==0){
            int k=2;
            while(k<=n){
                cout << k << " " << k-1 << " ";
                k+=2;
            }
        } else {
            int k=2;
            while(k<n-2){
                cout << k << " " << k-1 << " ";
                k+=2;
            }
            cout << n << " " << n-2 << " " << n-1 << " ";
        }
        cout << endl;
    }
    return 0;
}
