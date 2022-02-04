#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell{
    int x;
    int y;
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v (n,vector<int> (m,0) );
    queue<Cell> q;
    for(int y=(n-1)/2;2*y<=n;y++){
        for(int x=(m-1)/2;2*x<=m;x++){
            q.push({x,y});
            v[y][x] = m/2 + n/2;
        }
    }
    for(int i=0;i<m*n; i++){
        Cell c = q.front();
        q.pop();
        int x = c.x;
        int y = c.y;
        cout << v[y][x] << endl;
        if(x!=0){
            int new_x = x-1;
            int new_y = y;
            if(v[new_y][new_x]==0){
                v[new_y][new_x] = v[y][x]+1;
                q.push({new_x,new_y});
            }
        }
        if(x!=m-1){
            int new_x = x+1;
            int new_y = y;
            if(v[new_y][new_x]==0){
                v[new_y][new_x] = v[y][x]+1;
                q.push({new_x,new_y});
            }
        }
        if(y!=0){
            int new_x = x;
            int new_y = y-1;
            if(v[new_y][new_x]==0){
                v[new_y][new_x] = v[y][x]+1;
                q.push({new_x,new_y});
            }
        }
        if(y!=n-1){
            int new_x = x;
            int new_y = y+1;
            if(v[new_y][new_x]==0){
                v[new_y][new_x] = v[y][x]+1;
                q.push({new_x,new_y});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
