#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n ;
        long long biggest_odd=1;
        long long multiples_of_2=1;
        long long sum_odds=0;
        for(int j=0;j<n; j++){
            int x;
            cin >> x;
            while(x%2==0){
                x/=2;
                multiples_of_2 *= 2;
            }
            sum_odds += x;
            if(x>biggest_odd) biggest_odd = x;
        }
        cout << sum_odds-biggest_odd+biggest_odd*multiples_of_2 << endl;
    }
    return 0;
}
