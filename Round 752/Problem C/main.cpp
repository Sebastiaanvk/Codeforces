#include <iostream>

using namespace std;

bool somewhere_not_divisible(int d, int x){
    while(d>=2){
        if(x%d!=0){
            return true;
        }
        d--;
    }
    return false;
}

void check_removable(){
    int n;
    cin >> n;
    bool good = true;
    for(int j=1; j<=n; j++){
        int x;
        cin >> x;
        if(good && !somewhere_not_divisible(j+1,x)){
            good = false;
        }

    }
    if(good)    cout << "YES\n";
    else        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    for( int i=0; i<t; i++){
        check_removable();
    }
    return 0;
}
