#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long P = 1000000007;

void solve(){
    int n,p;
    cin >> n >> p;
    vector<long long> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    unordered_set<int> s;



    vector<long long> fill_spec_bits(p+1);
    fill_spec_bits[0] = 1;
    fill_spec_bits[1] = 1;
    for(int i=2;i<=p;i++) fill_spec_bits[i]=(fill_spec_bits[i-1]+fill_spec_bits[i-2])%P;

    vector<long long> fill_bits(p+1);
    fill_bits[0] = 1;
    for(int i=1;i<=p;i++) fill_bits[i] = (fill_bits[i-1]+fill_spec_bits[i])%P;


    long long total = 0;

    for(auto x:v){
        if(p<=31&&x>=(1<<p) ){
            break;
        } else {
            int y = x;
            bool already_in = false;
            while(!already_in&&y!=0){
                if( s.count(y) ){
                    already_in=true;
                }
                if(y%2==1){
                    y = (y-1)/2;
                } else if(y%4==0){
                    y = y/4;
                } else{
                    y=0;
                }
            }
            if(!already_in){
                s.insert(x);
                int bits = 1;
                while( (x>>bits)!=0 ){
                    bits++;
                }
                total = (total+fill_bits[p-bits])%P;
            }
        }
    }
    cout << total << '\n';

}

int main()
{
    solve();
    return 0;
}
