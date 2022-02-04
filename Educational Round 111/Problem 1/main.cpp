#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        int s = round( sqrt(t) );
        if( t==s*s ){
            cout << s << endl;
        } else if( s*s<t ){
            cout << s+1 << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}
