#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> top_doors, side_doors;
    for(int i=0; i<n-1; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        top_doors.push_back(n-b);
        side_doors.push_back(n-c);
    }


    int dist = floor(sqrt(n));
// We calculate the distances to all the doors from certain layers.
// The number of these layers is sqrt of the total number of layers
// If a query contains such a layer between the two points, we can quickly calculate the min distance
// If a query doesn't contain such a layer between the two points, the distance is small enough that we can calc the distance without help
// This will make the complexity sqrt(n)*n, which should be fast enough hopefully.
// Sadly there is no time to finish the program.
    map<int,int> elite_index;
    map<pair<int,int>,int> top_to_top;
    map<pair<int,int>,int> top_to_side;
    map<pair<int,int>,int> side_to_top;
    map<pair<int,int>,int> side_to_side;

    for(int i = dist/2, index=0; i<n; i+= dist,index++){
        elite_index[i] = index;
        top_to_top[i,i] = 0;
        top_to_side[i,i] = top_doors[i]+side_doors[i];
        side_to_top[i,i] = top_doors[i]+side_doors[i];
        side_to_side[i,i] = 0;
        for(int layer = i-1; layer>=0; layer--){
            top_to_top[i,layer] = min( top_to_top[i,layer+1]+ abs(top_doors[layer]-top_doors[layer+1]),top_to_side[i,layer+1]+side_doors[layer+1]+top_doors[layer]);
            top_to_side[i,layer] = min( top_to_top[i,layer+1]+top_doors[layer+1]+side_doors[layer],top_to_side[i,layer+1]+abs(side_doors[layer]-side_doors[layer+1]));

        }
    }

}

int main()
{
    solve();
    return 0;
}
