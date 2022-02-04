#include <iostream>

using namespace std;

int correct_n(int x, int y){

}


int main()
{
    int t;
    cin >> t;
    for( int i=0; i<t; i++){
        int x,y;
        cin >> x;
        cin >> y;
        if(x==y) cout << x << endl;
        else if(y>x)  cout << y-( (y%x)/2 ) << endl;
        else cout << x+y << endl;


    }
    return 0;
}
