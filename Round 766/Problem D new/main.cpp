#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int gcd(int x,int y){
    if(x>y) swap(x,y);
    int r = y%x;
    while(r!=0){
        y=x;
        x=r;
        r=y%x;
    }
    return x;
}

void solve(){
    int n;
    cin >> n;
    unordered_set<int> numbers_found;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        numbers_found.insert(x);
        v.push_back(x);
    }
    long long added = 0;


    while(v.size()>0){
        vector<int> new_v;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size(); j++){
                int g = gcd(v[i],v[j]);
                if(numbers_found.count(g)==0){
                    added++;
                    numbers_found.insert(g);
                    new_v.push_back(g);
                }
            }
        }
        v = new_v;
    }
    cout << added << endl;
}

int main()
{
    solve();
    return 0;
}
