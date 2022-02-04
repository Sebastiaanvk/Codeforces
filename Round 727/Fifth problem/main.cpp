#include <iostream>
#include <vector>


using namespace std;

int n;


struct Turn{
    int k;
    int a_left;
    int b_left;
    int a_right;
    int b_right;

};

bool dfs(const vector<Turn>& v, vector<bool>& path, int& i, int left, int right){
    if( i==n ){
        return true;
    }
    if( v[i].a_left<=v[i].k && v[i].a_right>=v[i].k && v[i].b_left<=right && v[i].b_right>=right  ){
        path.push_back(0);
        i++;
        if( dfs(v,path,i,v[i-1].k,right) ){
            return true;
        }
        i--;
        path.pop_back();

    }

    if( v[i].b_left<=v[i].k && v[i].b_right>=v[i].k && v[i].a_left<=left && v[i].a_right>=left  ){
        path.push_back(1);
        i++;
        if( dfs(v,path,i,left,v[i-1].k) ){
            return true;
        }
        i--;
        path.pop_back();

    }

    return false;
}

int main()
{

    cin >> n;
    int m;
    cin >> m;
    vector<Turn> v;
    for(int i=0;i<n;i++){
        Turn t;
        cin >> t.k >> t.a_left >> t.a_right >> t.b_left >> t.b_right;
        v.push_back(t);
    }
    vector<bool> path;
    int left=0;
    int right=1;
    int index = 0;
    if( dfs(v,path,index,0,1) ){
        cout << "Yes\n";
        for( int i=0; i<n-1 ;i++){
            cout << path[i] << " ";
        }
        cout << path[n-1];
    } else {
        cout << "No";
    }

    return 0;
}
