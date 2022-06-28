#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    int nr_zeros = 0;
    int nr_positives = 0;
    int nr_negatives = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]==0) nr_zeros++;
        else if(v[i]>0) nr_positives++;
        else nr_negatives++;
    }
    if(nr_positives>2||nr_negatives>2){
        cout << "NO\n";
    } else if(nr_zeros>0){
        if(nr_positives==2||nr_negatives==2){
            cout << "NO\n";
        } else if(nr_positives==0||nr_negatives==0){
            cout << "YES\n";
        } else {
            long long sum = 0;
            for(int i=0; i<n;i++){
                sum += v[i];
            }
            if(sum==0){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    } else {
        if(n==3){
            long long sum = 0;
            for(int i=0; i<n;i++){
                sum += v[i];
            }
            if(sum == v[0]||sum==v[1]||sum==v[2]){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        } else if(n==4){
            long long sum = 0;
            bool ok = true;
            for(int i=0; i<n;i++){
                sum += v[i];
            }
            for(int i=0; i<n;i++){
                long long left = sum - v[i];
                bool in = false;
                for(int i=0; i<n; i++){
                    if(v[i]==left) in = true;
                }
                if(!in) ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
