#include <iostream>
#include <vector>

using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<bool> v(n+1,false);
    bool possible=true;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(possible){
            while(x>n||(x>0&&v[x]) ){
                x/=2;
            }
            if(x==0) possible=false;
            else        v[x]=true;
        }
    }

    return possible;
}

int main()
{
    int t;
    cin >> t;
    while(t--) cout << (solve()?"YES\n":"NO\n");
    return 0;
}
