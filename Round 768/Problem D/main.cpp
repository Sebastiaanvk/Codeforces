#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a (n+1);
    map<int,int> occ;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( occ.count(a[i])==0 ){
            occ[a[i]]=1;
        } else {
            occ[a[i]]++;
        }
    }
    map<int,int>::iterator it1 = occ.begin();
    map<int,int>::iterator it2 = occ.begin();
    int smallest_range=INT_MAX;
    int l,r;
    int current_inbetween = it1->second;
    while(it2!=occ.end()){
        while(2*current_inbetween-n<k){
            it2++;
            if(it2!=occ.end()){
                current_inbetween += it2->second;
            } else {
                break;
            }
        }
        if(it2!=occ.end()){
            if( (it2->first)+1 -(it1->first)<smallest_range ){
                l=it1->first;
                r=it2->first;
                smallest_range = (it2->first)+1 -(it1->first);
            }
        }
        current_inbetween -= it1->second;
        it1++;
    }
    cout << l << " " << r << '\n';
    int pos=1;
    for(int i=0;i<k-1;i++){
        int init_pos = pos;
        int in_range=0;
        int out_range=0;
        while(in_range!=out_range+1){
            if(a[pos]<l||a[pos]>r){
                out_range++;
            } else {
                in_range++;
            }
            pos++;
        }
        cout << init_pos << " " << pos-1 << '\n';
    }
    cout << pos << " " << n << '\n';

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
