#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v;
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int biggest_min = v[0];
        int change=0;
        for(int left=0; left<n; left++){
            if(v[left]+change>biggest_min){
                biggest_min=v[left]+change;
            }
            change += (-1)*(v[left]+change);
        }
        cout << biggest_min << endl;

    }
    return 0;
}
