#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        bool missing_middle_bigram = false;
        char c1,c2;
        cin >> c1 >> c2;
        cout << c1 << c2;
        for(int j=1 ; j<n-2; j++){
            cin >> c1;
            if(c2!=c1){
                missing_middle_bigram = true;
                cout << c1;
            }
            cin >> c2;
            cout << c2;
        }

        if(!missing_middle_bigram){
            cout << 'a';
        }

        cout << endl;
    }
    return 0;
}
