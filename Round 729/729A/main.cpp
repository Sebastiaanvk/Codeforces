#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        int odds=0;
        int evens=0;
        for(int j=0;j<2*n;j++){
            int x;
            cin >> x;
            if(x%2==0){
                evens++;

            } else {
                odds++;
            }
        }
        if(odds==evens){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}
