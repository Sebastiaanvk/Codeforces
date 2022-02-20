#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a;
    cin >> a;
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        a = a|x;
    }
    printf("%d\n",a);
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
