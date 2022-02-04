#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, k;
        cin >> n >> k;
        if(k<=(n+1)/2){
            for(int j=0; j<n; j++){
                string s;
                for(int m=0; m<n; m++){
                    s += '.';
                }
                if( j%2==0&&j<=(k-1)*2 ){
                    s[j]='R';
                }
                cout << s << endl;
            }

        } else {
        cout << -1 << endl;
        }
    }
    return 0;
}
