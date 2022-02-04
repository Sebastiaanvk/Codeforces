#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,m;
        cin >> n;
        cin >> m;
        vector<int> seq;
        for(int j=0; j<n; j++){
            seq.push_back(INT_MAX);
        }
        for( int j=0; j<m; j++){
            int l, r, x;
            cin >> l >> r >> x;
            for(int k=l-1; k<r; k++){
                seq[k] = seq[k]&x;
            }
        }

    }
    return 0;
}
