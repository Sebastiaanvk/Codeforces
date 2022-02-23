#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Op{
    int loc;
    int val;
};

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> odd_amounts;

    for(int i=0; i<n; i++){
        cin >> v[i];
        if(odd_amounts.count(v[i])){
            odd_amounts.erase(v[i]);
        } else {
            odd_amounts.insert(v[i]);
        }
    }

    if(!odd_amounts.empty()){
        cout << -1 << '\n';
        return;
    }

    int offset = 0;
    int current_pos = 0;
    vector<int> tandem_parts;
    vector<Op> operations;
    while(current_pos!=n){
        int first_dupe = current_pos+1;
        while(v[first_dupe]!=v[current_pos]){
            first_dupe++;
        }
        tandem_parts.push_back(first_dupe-current_pos);
        for(int i=current_pos+1;i<first_dupe;i++){
            operations.push_back({offset+i-current_pos+first_dupe,v[i]});
            //cout << offset+i-current_pos+first_dupe << " " << v[i] <<'\n';
        }
        offset += (first_dupe-current_pos-1)*2;
        int i=current_pos+1;
        int j=first_dupe;
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
        current_pos+=2;
    }
    cout << operations.size() << '\n';
    for(int i=0; i<operations.size(); i++){
        cout << operations[i].loc << " " << operations[i].val << '\n';
    }
    cout << tandem_parts.size() << '\n';
    for(auto x:tandem_parts) cout << 2*x << " ";
    cout << '\n';

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
