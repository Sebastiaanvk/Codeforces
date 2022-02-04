#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for( int i=0; i<t; i++){
        int x;
        int a1,a2,a3;
        cin >> a1 >> a2 >> x >> x >> x >> x >> x;
        cout << a1 << " " << a2 << " " << x-a1-a2 << endl;
    }
    return 0;
}
