#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long sum_fourth_quadr=0;
    long long min_corn=INT_MAX;
    for(int row=1;row<=2*n;row++){
        for( int col=1; col<=2*n;col++){
            long long x;
            cin >> x;
            if((row==1||row==n)&&(col==n+1||col==2*n) ){
                min_corn = min(min_corn,x);
            } else if( (row==n+1||row==2*n)&&(col==1||col==n) ){
                min_corn = min(min_corn,x);
            }

            if(row>n&&col>n){
                sum_fourth_quadr += x;
            }
        }
    }
    cout << sum_fourth_quadr+min_corn << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}
