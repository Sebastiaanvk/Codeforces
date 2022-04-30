#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long P = 1000000007;
vector<int> v (40001,0);

void solve(){
    int n;
    cin >> n;
    cout << v[n] << '\n';
}

void add_pal(int pal){
    for(int i=1;i<=40000;i++){
        if(i==pal) {
                v[i] = (v[i]+1) %P;
        }else if(i>pal){
            v[i] =(v[i]+ v[i-pal])%P;
        }
    }
}

void setup(){
    for(int i=1; i<10; i++){
        int pal = i;
        add_pal(pal);
    }
    for(int i=1; i<10; i++){
        int pal = i*11;
        add_pal(pal);
    }
    for(int i=10; i<100; i++){
        int pal = i*10+i/10;
        add_pal(pal);
    }
    for(int i=10; i<100; i++){
        int pal = i*100+(i%10)*10+i/10;
        add_pal(pal);
    }
    for(int i=100; i<400; i++){
        int pal = i*100+((i/10)%10)*10+i/100;
        add_pal(pal);
    }
}

int main()
{
    setup();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
