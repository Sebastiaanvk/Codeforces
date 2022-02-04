#include <iostream>
#include <vector>

using namespace std;

const int M = 998244353;


int check_extreme_values(){
    int total_extreme_values = 0;
    int n;
    cin >> n;
    vector<int> values;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        values.push_back(x);
    }
    for(int j=0; j<n; j++){
        int current_extreme_values = 0;
        int left_most = values[j];
        for( int i=j-1; i>=0; i--){
            int x = values[i];
            if(x>left_most){
                int split = (x-1)/left_most;
                current_extreme_values = (current_extreme_values+split)%M;
                left_most = x/(split+1);
            } else {
                left_most=x;
            }

            total_extreme_values = (total_extreme_values+current_extreme_values)%M;
        }
    }


    cout << total_extreme_values << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        check_extreme_values();
    }
    return 0;
}
