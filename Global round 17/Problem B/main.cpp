#include <iostream>
#include <vector>

using namespace std;

bool try_removing(const vector<int>& v, int left, int right, int chosen){
    while(left<right){
        if(v[left]==v[right]){
            left++;
            right--;
        } else if(v[left]==chosen){
            left++;
        } else if(v[right]==chosen){
            right--;
        } else {
            return false;
        }

    }
    return true;
}

bool is_kalindrome(const vector<int>& v){
    int left=0;
    int right=v.size()-1;
    while( left<right ){
        if(v[left]!=v[right]){
            if(try_removing(v, left+1,right,v[left])){
                return true;
            } else {
                return try_removing(v,left,right-1,v[right]);
            }
        }
        left++;
        right--;
    }
    return true;
}


int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> v;
        for( int j=0;j<n;j++ ){
            int x;
            cin >> x;
            v.push_back(x);
        }
        if(is_kalindrome(v)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }
    return 0;
}
