#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    map<int,int> left_most;
    map<int,int> right_most;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        if(left_most.count(v[i])==0){
            left_most[v[i]]=i;
        }
        right_most[v[i]]=i;
    }
    int pos=1;
    int colored = 0;
    while(pos<=n){
        int x=v[pos];
        if(right_most[x]!=pos){
            while(true){
                int new_x=x;
                int right=right_most[x];
                colored += right_most[x]-pos-1;
                pos++;
                while(pos<right_most[x]){
                    if(right_most[v[pos]]>right){
                        right=right_most[v[pos]];
                        new_x=v[pos];
                    }
                    pos++;
                }
                if(new_x==x){
                    break;
                } else {
                    x=new_x;
                }
            }
        }
        pos++;
    }

    cout << colored << '\n';
}

int main()
{
    solve();
    return 0;
}
