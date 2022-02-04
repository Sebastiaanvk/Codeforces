#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Building{
    int id;
    long long visits;
};

bool operator<(const Building& b1, const Building& b2){
    return b1.visits<b2.visits;
}

bool operator==(const Building& b1, const Building& b2){
    return b1.visits==b2.visits;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<Building> bs;
        for( int j=1; j<=n; j++){
            long long visits;
            cin >> visits;
            bs.push_back({j,visits});
        }
        sort(bs.begin(),bs.end());
        int pos=bs.size()-1;
        long long walk_time=0;
        long long location[n+1];
        location[0]=0;
        long long left = 1;
        long long right = 1;
        while(pos>=1){
            walk_time += 2*left*bs[pos].visits+2*right*bs[pos-1].visits;
            location[bs[pos].id ] = -1*left;
            location[ bs[pos-1].id ] = right;
            left++;
            right++;
            pos-=2;
        }
        if(pos==0){
            walk_time += 2*right*bs[pos].visits;
            location[ bs[pos].id ] = right;
        }
        cout << walk_time << endl;
        for(int j=0; j<=n; j++){
            cout << location[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
