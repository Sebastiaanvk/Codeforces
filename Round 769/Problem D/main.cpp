#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    if(x>y) swap(x,y);
    int r=y%x;
    while(r!=0){
        y=x;
        x=r;
        r=y%x;
    }
    return x;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int total_changes=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        int g = v[i];
        if(v[i]==1){
            v[i]=-1;
            total_changes++;
        } else {
            int g = v[i];
            for(int pos=i-1;pos>=0&&v[pos]!=-1&&g>=i+1-pos;pos--){
                g = gcd(g,v[pos]);
                if(g==i+1-pos){
                    v[i]=-1;
                    total_changes++;
                    break;
                }
            }
        }
        cout << total_changes << " ";
    }
    cout << '\n';
}

int main()
{
    solve();
    return 0;
}
