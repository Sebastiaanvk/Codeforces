#include <iostream>
#include <bits/stdc++.h>
#define watch(x) cout << #x << ": " << x << '\n';

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v (n);
    vector<int> occurences(n+1,0);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        occurences[v[i]]++;
    }
    vector<int> answer;
    int pos=0;
    while(pos<n){
        int x = 0;
        set<int> s;
        while(x<=n&&occurences[x]!=0){
            s.insert(x);
            x++;

        }
        answer.push_back(x);
        if(x!=0){
            while(!s.empty()){
                s.erase(v[pos]);
                occurences[v[pos]]--;
                pos++;
            }
        } else {
            pos++;
        }
    }

    cout << answer.size() << '\n';
    for(auto x:answer) cout << x << " ";
    cout << '\n';

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
