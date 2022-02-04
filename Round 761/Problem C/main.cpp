#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void program(){
    int n;
    cin >> n;
    vector<int> left_overs;
    vector<bool> already_in(n+1,false);
    for( int j=0; j<n; j++){
        int x;
        cin >> x;
        if(x<=n&&!already_in[x]){
            already_in[x] = true;
        } else {
            left_overs.push_back(x);
        }
    }
    sort(left_overs.begin(),left_overs.end());
    int index = 0;
    for(int x=1; x<=n; x++){
        if(!already_in[x]){
            if(left_overs[index]<=2*x){
                cout << -1 << endl;
                return;
            } else {
                index++;
            }
        }
    }
    cout << left_overs.size() << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        program();
    }
    return 0;
}
