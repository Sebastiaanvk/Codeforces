#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long P = 1000000007;

void solve(){
    long long b_beg,b_diff, b_nr, b_end;
    cin >> b_beg >> b_diff >> b_nr;
    b_end = b_beg + b_diff*(b_nr-1);

    long long c_beg, c_diff, c_nr, c_end;
    cin >> c_beg >> c_diff >> c_nr;
    c_end = c_beg + c_diff*(c_nr-1);

    if( (c_diff%b_diff)!=0 ){
        cout << 0 << '\n';
        return;
    }
    if( c_beg<b_beg || c_end>b_end || ((c_beg-b_beg)%b_diff)!=0){
        cout << 0 << '\n';
        return;
    }

    if(c_beg-b_beg<c_diff || b_end-c_end<c_diff){
        cout << -1 << '\n';
        return;
    }

    long long answer = 0;
//Need to fix this. ONly works if gcd(b_diff,c_diff/b_diff) is 1
//Thats why it didn't work yet, but didn't have enough time to fix :/
    long long min_a_diff = c_diff/b_diff;

    long long qrt = c_diff/min_a_diff;

    for(long long d=1; d*d<=qrt; d++){
        if(b_diff%d==0){
            answer = (answer + d*d)%P;
            long long e = qrt/d;
            if(e!=d){
                answer = (answer + e*e)%P;
            }
        }

    }
    cout << answer << '\n';

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
