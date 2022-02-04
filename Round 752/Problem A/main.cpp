#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int max_dif=0;
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;
            if(x-j>max_dif){
                max_dif=x-j;
            }
        }
        cout << max_dif << endl;
    }
    return 0;
}
