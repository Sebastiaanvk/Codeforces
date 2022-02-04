#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if(b>=0){
            cout << n*(a+b) << endl;
        } else {
            int swaps = 0;
            for(int j=0; j<s.size()-1; j++){
                if(s[j]!=s[j+1]){
                    swaps++;
                }
            }
            int min_removals=1+(swaps+1)/2;
            cout << n*a+b*min_removals << endl;
        }

    }
    return 0;
}
