#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int max_a= INT_MIN;
    for(int i =0; i< n; i++){
        int x;
        cin >> x;
        max_a = max(max_a,x);
    }
    int m;
    cin >> m;
    int max_b= INT_MIN;
    for(int i =0; i< m; i++){
        int x;
        cin >> x;
        max_b = max(max_b,x);
    }
    if(max_a>max_b){
        cout << "Alice\nAlice\n";
    } else if(max_a==max_b){
        cout << "Alice\nBob\n";
    } else {
        cout << "Bob\nBob\n";
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
