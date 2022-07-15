#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void add_to_intervals(int x, map<int,int>& intervals){
    map<int,int>::iterator it = intervals.lower_bound(x);
    if(it!=intervals.end()&&it->first==x){
        int right = it->second;
        intervals.erase(it);
        add_to_intervals(right+1,intervals);
        return;
    }
    int new_left = x;
    int new_right = x;
    if(it!=intervals.begin()){
        it = it--;
        if(x>(it->first)&&x<=(it->second){
            int left = it->first;
            int right = it->second;
            intervals[first] = x-1;
            add_to_intervals(right+1,intervals);
            return;
        }
        if(it->second==x-1){
            new_left = it->first;
        }
    }

    it++;
    if(it!=intervals.end()){
        if(it->first == x+1){
            map.erase(it);
        }
    }
    intervals
}

void solve(){
    int n,q;
    cin >> n >> q;
    map<int,int> intervals;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        add_to_intervals(x, intervals);
    }




}

int main()
{
    solve();
    return 0;
}
