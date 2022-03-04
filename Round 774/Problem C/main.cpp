#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nr_k(long long target, const vector<long long>& fact, int index){
    if(target==0){
        return 0;
    }
    int k=0;
    long long n=target;
    while(n!=0){
        if(n%2==1) k++;
        n = n>>1;
    }
    if(k==1)
        return 1;
    for(int i=index; i>2; i--){
        if(fact[i]<=target){
            k = min(k , 1+nr_k(target-fact[i],fact, i-1));
        }
    }
    return k;
}

void solve(){
    long long n;
    cin >> n;
    vector<long long> fact;
    long long f = 1;
    long long p=1;
    while(f<=n){
        fact.push_back(f);
        f*=p;
        p++;
    }
    cout << nr_k(n,fact,fact.size()-1) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
