#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int m=0;
    int mi=INT_MAX;
    while(n--){
        int x;
        cin >> x;
        m=max(m,x);
        mi=min(mi,x);
    }
    cout << m-mi << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
