#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, a, b;
        cin >> n >> a >> b;


        if(a<n/2+1&&b>n/2){
            for(int i=n; i>=1; i--){
                if(i==a)
                    cout << b;
                else if(i==b)
                    cout << a;
                else
                    cout << i;
                if(i!=1){
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        } else if(b==n/2&&a==n/2+1){
            for(int i=n; i>1; i--){
                cout << i << " ";
            }
            cout << 1 << endl;
        }else {
            cout << -1 << endl;
        }
    }

    return 0;
}
