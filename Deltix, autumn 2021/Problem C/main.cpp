#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX = 1000000;

void make_primes(set<int>& primes){
    bool numbers [MAX+1] = {false};

    for( int i=3; i<=MAX; i+=2){
        numbers[i]=true;
    }
    numbers[2]=true;
    primes.insert(2);


    for(int i=3; i<MAX; i+=2){
        if(numbers[i]){
            primes.insert(i);
            for( int p=2*i; p<=MAX; p+=i) numbers[p]=false;
        }
    }
}

int main()
{
    set<int> primes;
    make_primes(primes);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, e;
        cin >> n >> e;
        vector<int> arr;
        int x;
        for( int j=0; j<n; j++){
            cin >> x;
            if(x==1){
                arr.push_back(1);
            } else if( primes.count(x) ){
                arr.push_back(2);
            }else {
                arr.push_back(0);
            }
        }
        long long cnt=0;
        for( int j=0; j<arr.size(); j++){
            if( arr[j]==2 ){
                long long right=0;
                int loc = j+e;
                while(loc<arr.size()&&arr[loc]==1){
                    right++;
                    loc+=e;
                }
                long long left=0;
                loc = j-e;
                while(loc>=0&&arr[loc]==1){
                    left++;
                    loc-=e;
                }
                cnt += (left+1)*(right+1)-1;
            }

        }
        cout << cnt << endl;
    }
    return 0;
}
