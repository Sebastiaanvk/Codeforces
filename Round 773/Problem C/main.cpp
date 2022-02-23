#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> state_of_patients(n+1,0) //0 unknown, 1 not sick, 2 sick
    vector<list<int>> lists_sick_queries;
    vector<list<int>> sick_queries_patients_indices; // s[x] is
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        if(t==0){
            int l,r,x;
            cin >> l >> r >> x;
            if(x==0){
                for(int p=l;p<=r;p++){
                    if(state_of_patients[p]==0){
                        state_of_patients[p]=1;
                        for(auto j:sick_queries_patients_indices){

                        }
                    }
                }
            } else {

            }
        } else {
            int j;
            cin >> j;
            if(state_of_patients[j]==0){
                cout << "N/A\n";
            } else if(state_of_patients[j]==1){
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}
