#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> canvas(n+1, vector<int>(m+1));
    for(int row=1; row<=n; row++){
        for(int col=1; col<=m; col++){
            cin >> canvas[row][col];
        }
    }
    vector<int> row_doubles (n+1);
    vector<int> col_doubles (m+1);
    for(int row=1;row<=n;row++){
        for(int col=2; col<=m; col++){
            if(canvas[row][col]==canvas[row][col-1]) row_doubles[row]++;
        }
        if(row_doubles[row]==0){
            cout << -1 << '\n';
            return;
        }
    }
    for(int col=1; col<=m; col++){
        for(int row=2;row<=n;row++){
            if(canvas[row][col]==canvas[row-1][col]) col_doubles[col]++;
        }
        if(col_doubles[col]==0){
            cout << -1 << '\n';
            return;
        }
    }

    int nr_perfect_squares = 0;
    int row_start;
    int col_start;
    for(int row=2;row<=n;row++){
        for(int col=2;col<=m;col++){
            if(canvas[row][col]==canvas[row-1][col]&&canvas[row][col]==canvas[row][col-1]&&canvas[row][col]==canvas[row-1][col-1]){
                nr_perfect_squares++;
                int row_start=row-1;
                int col_start=col-1;
            }
        }
    }
    if(nr_perfect_squares==0){
        cout << -1 << '\n';
        return;
    }

    int row_up=row_start;
    int row_down = row_start+1;
    int col_left = col_start;
    int col_right = col_start+1;




}

int main()
{
    solve();
    return 0;
}
