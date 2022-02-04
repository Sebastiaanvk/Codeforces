#include <iostream>

using namespace std;

bool solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if( (2*b-a>0)&& (2*b-a)%c==0 ){
        return true;
    }
    if( (c-a)%2==0&&a+(c-a)/2>0&&(a+(c-a)/2)%b==0 ) return true;

    if(2*b-c>0&&(2*b-c)%a==0) return true;

    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        if(solve()) cout << "YES\n";
        else        cout << "NO\n";
    }
    return 0;
}
