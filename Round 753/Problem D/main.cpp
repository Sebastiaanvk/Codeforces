#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& reds, vector<int>& blues, int& n){
    for(int i=1; i<=blues.size(); i++){
        if( blues[i-1] < i){
            return false;
        }
    }
    int v = n;
    for(int i=reds.size()-1; i>=0; i--){
        if(reds[i]>v){
            return false;
        }

        v--;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    vector<int> values;
    vector<bool> colours; //Red is true
    vector<int> blues;
    vector<int> reds;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        values.clear();
        colours.clear();
        blues.clear();
        reds.clear();
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            values.push_back(x);
        }
        for(int j=0;j<n;j++){
            char c;
            cin >> c;
            if(c=='R'){
                colours.push_back(true);
            } else {
                colours.push_back(false);
            }
        }
        for(int j=0;j<n;j++){
            if(colours[j]){
                reds.push_back(values[j]);
            } else {
                blues.push_back(values[j]);
            }
        }
        sort(reds.begin(),reds.end());
        sort(blues.begin(), blues.end());

        if( possible(reds,blues,n) ){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
