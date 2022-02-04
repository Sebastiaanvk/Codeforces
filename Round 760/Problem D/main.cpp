#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for( int j=0; j<n; j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());

        long long total = 0;
        for(int j=0; j<n-2*k; j++) total += v[j];
        int max_multiple = 0;
        int current_multiple=1;
        for(int j=n-2*k; j<n-1; j++){
            if(v[j]==v[j+1]){
                current_multiple++;
                if(current_multiple>max_multiple){
                    max_multiple = current_multiple;
                }
            } else {
                current_multiple=1;
            }
        }
        if(max_multiple>k) total += max_multiple-k;
        cout << total << endl;

    }
    return 0;
}
