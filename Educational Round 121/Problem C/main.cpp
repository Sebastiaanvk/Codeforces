#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct SE{
    bool start;
    long long time;
    long long index;
};

bool operator<(const SE& s1, const SE& s2){
    if(s1.time<s2.time){
        return true;
    }
    if(s1.time==s2.time){
        if(s1.start==s2.start){
            return s1.index<s2.index;
        }
        return s1.start&&!s2.start;
    }
    return false;
}

//bool operator==(const SE& s1, const SE& s2){
//    return (s1.time==s2.time)&&(s1.start==s2.start)&&(s1.index==s2.index);
//}

void solve(){
    int n;
    cin >> n;
    set<SE> events;
    vector<long long> times;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        times.push_back(x);
    }
    for(int i=0;i<n;i++){
        long long h;
        cin >> h;
        events.insert({false,times[i],i});
        events.insert({true,times[i]-h+1,i});
    }
    long long mana_spent=0;
    long long current_starting_time;
    set<long long> currently_in;
    for(auto x:events){
        if(currently_in.empty()){
            current_starting_time=x.time;
            currently_in.insert(x.index);
        } else if(!x.start){
            currently_in.erase(x.index);
            if(currently_in.empty()){
                long long m = x.time-current_starting_time+1;
                mana_spent += m*(m+1)/2;
            }
        } else {
            currently_in.insert(x.index);
        }

    }
    cout << mana_spent << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
