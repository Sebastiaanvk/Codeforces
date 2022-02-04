#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int roll=0;
    if(k!=0){
        while(k>>roll!=1){
            roll++;
        }
    }
    map<int, list<int>> numbs;

    map<int,int> numbs_to_ints;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        numbs[x>>(roll+1)].push_back(x);
        numbs_to_ints[x]=i+1;
    }
    if(k==0){
        cout << n << '\n';
        return;
    }
    map<int,list<int>>::iterator it = numbs.begin();
    int total=0;
    vector<int> v;
    for(;it!=numbs.end();it++){
        int y = it->first;
        total++;
        bool pair_found=false;
        list<int> second = it->second;
        list<int>::iterator it2;
        for(it2=second.begin();!pair_found&&it2!=second.end();it2++){
            list<int>::iterator it3;
            for(it3=second.begin();!pair_found&&it3!=second.end();it2++){
                if(*it3^*it2>=k){
                    v.push_back(*it3);
                    v.push_back(*it2);
                    total++;
                    pair_found=true;
                }
            }
        }
        if(!pair_found){
            v.push_back( second.front() );
        }

    }
    cout << total << endl;
    for(auto x:v) cout << numbs_to_ints[x] << " ";
    cout << '\n';
}

int main()
{
    solve();
    return 0;
}
