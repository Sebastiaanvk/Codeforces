#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n, l;
    cin >> n >> l;
    vector<int> v(l,0);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int p=0;
        while(x!=0){
            if(x%2==1){
                v[p]++;
            }
            x/=2;
            p++;
        }
    }
    int result=0;
    for(int p=0,r=1;p<l;p++,r*=2){
        if(v[p]>n/2){
            result += r;
        }
    }
    cout << result << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
