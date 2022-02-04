#include <iostream>
#include<set>
#include<vector>
using namespace std;

void solve(){
    string s;
    cin >> s;
    set<char> singles;
    vector<char> doubles;
    for(char c:s){
        if(singles.count(c)){
            doubles.push_back(c);
            singles.erase(c);
        }else {
            singles.insert(c);
        }
    }
    for(char c:doubles) cout << c;
    for(char c:doubles) cout << c;
    for(char c:singles) cout << c;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
