#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        int x,y,s,t;
        cin >> x >> y;

        if(x%2==0&&y%2==0){
            s=x/2;
            t=y/2;
        } else if(x%2==1&&y%2==1){
            s=x/2;
            t=y/2+1;
        } else {
            s=-1;
            t=-1;
        }
        cout << s << " " << t << endl;
    }
    return 0;
}
