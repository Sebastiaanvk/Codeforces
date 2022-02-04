#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ls(26,0);
    for(auto c:s){
        ls[c-'a']++;
    }
    int pairs=0;
    int singles=0;
    for(auto x:ls){
        if(x%2==1) singles++;
        pairs += x/2;
    }
    int mi=0;
    mi+=2*(pairs/k);
    singles+=2*(pairs-(pairs/k)*k );
    if(singles>=k) mi++;
    cout << mi << endl;

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
