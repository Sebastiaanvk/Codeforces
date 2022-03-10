#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> points(n);
    set<pair<int,int>> point_set;

    for(int i=0; i<n ;i++){
        int x,y;
        cin >> x >> y;
        points[i] = {x,y};
        point_set.insert({x,y});
    }
    map<pair<int,int>,pair<int,int>> point_map;
    queue<pair<int,int>> point_queue;
    set<pair<int,int>> added_to_queue;
    for(int i=0; i<n; i++){
        int x = points[i].first;
        int y = points[i].second;
        bool free_field = true;
        if(point_set.count({x+1,y})==0){
            point_map[{x,y}] = {x+1,y};
        } else if(point_set.count({x-1,y})==0){
            point_map[{x,y}] = {x-1,y};
        } else if(point_set.count({x,y+1})==0){
            point_map[{x,y}] = {x,y+1};
        } else if(point_set.count({x,y-1})==0){
            point_map[{x,y}] = {x,y-1};
        } else {
            free_field=false;
        }
        if(free_field){
            int v = x-1;
            int w = y;
            if( point_set.count({v,w}) && added_to_queue.count({v,w})==0 ){
                added_to_queue.insert({v,w});
                point_queue.push({v,w});
            }
             v = x+1;
             w = y;
            if( point_set.count({v,w}) && added_to_queue.count({v,w})==0 ){
                added_to_queue.insert({v,w});
                point_queue.push({v,w});
            }
             v = x;
             w = y-1;
            if( point_set.count({v,w}) && added_to_queue.count({v,w})==0 ){
                added_to_queue.insert({v,w});
                point_queue.push({v,w});
            }
             v = x;
             w = y+1;
            if( point_set.count({v,w}) && added_to_queue.count({v,w})==0 ){
                added_to_queue.insert({v,w});
                point_queue.push({v,w});
            }

        }
    }

    while(!point_queue.empty()){
        pair<int,int> p = point_queue.front();
        point_queue.pop();
        if(point_map.count(p)!=0){
            continue;
        }
        int x = p.first;
        int y = p.second;

        int min_dist = INT_MAX;

        int v = x-1;
        int w = y;
        if(point_map.count({v,w})){
            int new_v = point_map[{v,w}].first;
            int new_w = point_map[{v,w}].second;
            int diff = abs(new_v-x)+abs(new_w-y);
            if( diff<min_dist ){
                min_dist=diff;
                point_map[{x,y} ]= {new_v,new_w};
            }
        } else if(point_set.count({v,w}) && added_to_queue.count({v,w})==0){
            added_to_queue.insert({v,w});
            point_queue.push({v,w});
        }

         v = x+1;
         w = y;
        if(point_map.count({v,w})){
            int new_v = point_map[{v,w}].first;
            int new_w = point_map[{v,w}].second;
            int diff = abs(new_v-x)+abs(new_w-y);
            if( diff<min_dist ){
                min_dist=diff;
                point_map[{x,y} ]= {new_v,new_w};
            }
        } else if(point_set.count({v,w}) && added_to_queue.count({v,w})==0){
            added_to_queue.insert({v,w});
            point_queue.push({v,w});
        }

         v = x;
         w = y-1;
        if(point_map.count({v,w})){
            int new_v = point_map[{v,w}].first;
            int new_w = point_map[{v,w}].second;
            int diff = abs(new_v-x)+abs(new_w-y);
            if( diff<min_dist ){
                min_dist=diff;
                point_map[{x,y} ]= {new_v,new_w};
            }
        } else if(point_set.count({v,w}) && added_to_queue.count({v,w})==0){
            added_to_queue.insert({v,w});
            point_queue.push({v,w});
        }

         v = x;
         w = y+1;
        if(point_map.count({v,w})){
            int new_v = point_map[{v,w}].first;
            int new_w = point_map[{v,w}].second;
            int diff = abs(new_v-x)+abs(new_w-y);
            if( diff<min_dist ){
                min_dist=diff;
                point_map[{x,y} ]= {new_v,new_w};
            }
        } else if(point_set.count({v,w}) && added_to_queue.count({v,w})==0){
            added_to_queue.insert({v,w});
            point_queue.push({v,w});
        }
    }
    for(int i=0; i<n; i++){
        pair<int,int> p = points[i];
        pair<int,int> q = point_map[p];
        cout << q.first << " " << q.second << '\n';
    }
}

int main()
{
    solve();
    return 0;

}
