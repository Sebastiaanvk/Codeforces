#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v (n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    bool swap_found = false;
    int left, right;
    for(int row=0; row<n&&!swap_found; row++){
        left=0;
        while(left<m-1&&!swap_found){
            if(v[row][left]>v[row][left+1]){
                swap_found =true;
            } else {
                left++;
            }
        }
        if(swap_found){
            if(left==m-2||v[row][left+2]>v[row][left]){
                right = left+1;
            } else {
                right=left+2;
                while(right<m-1&&v[row][right]>v[row][left+1]){
                    right++;
                }
            }
        }
    }
    if(!swap_found){
        cout << 1 << " " << 1 << '\n';
        return;
    }
    for(int row=0; row<n; row++){
        swap(v[row][left],v[row][right]);
        for(int i=0; i<m-1; i++){
            if(v[row][i]>v[row][i+1]){
                cout << -1 << '\n';
                return;
            }
        }
    }


    cout << left+1 << " " << right+1 << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
