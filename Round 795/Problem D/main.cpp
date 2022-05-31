#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool fault_found(const vector<long long>& v, int left_limit, int right_limit){
    if(left_limit>=right_limit){
        return false;
    }
    int middle = (left_limit+right_limit)/2;
    long long current_sum_left = 0;
    long long current_sum_right = 0;
    long long max_sum_right = 0;
    int left = middle;
    int right = middle;
    int left_max = v[middle];
    while(left>=left_limit){
        if(v[left]>left_max) left_max = v[left];
        current_sum_left += v[left];
        while(right<right_limit&&v[right+1]<=left_max){
            right++;
            current_sum_right += v[right];
            max_sum_right = max(max_sum_right,current_sum_right);
        }
        if(current_sum_left+max_sum_right>left_max){
            return true;
        }
        left--;
    }

    current_sum_left = 0;
    current_sum_right = 0;
    long long max_sum_left = 0;
    left = middle;
    right = middle;
    int right_max = v[middle];
    while(right<=right_limit){
        if(v[right]>right_max) right_max = v[right];
        current_sum_right += v[right];
        while(left>left_limit&&v[left-1]<=right_max){
            left--;
            current_sum_left += v[left];
            max_sum_left = max(max_sum_left,current_sum_left);
        }
        if(current_sum_right+max_sum_left>right_max){
            return true;
        }
        right++;
    }

    if(fault_found(v,left_limit,middle-1)||fault_found(v,middle+1,right_limit)){
        return true;
    } else {
        return false;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(!fault_found(v, 0, n-1)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
