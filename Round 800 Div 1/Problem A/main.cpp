#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    int last_non_zero = -1;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]!=0){
            last_non_zero = i;
        }
    }
    long long current_value = 0;
    for(int i=last_non_zero; i>0; i--){
        current_value += v[i];
        if(current_value>=0)
            return false;
    }
    current_value += v[0];
    return (current_value==0);


}

int main()
{
    int t;
    cin >> t;
    while(t--){
        if(solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
