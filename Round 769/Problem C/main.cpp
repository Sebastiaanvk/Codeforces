#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,b;
    cin >> a >> b;
    if(a>b){
        cout << a-b << '\n';
        return;
    } else if(a==b){
        cout << 0 << '\n';
        return;
    }
    int m = (a|b)-b;
    if(m==0){
        cout << 1 << '\n';
        return;
    }
    int max_roll; //most bit where
    for(int roll=0;a>>roll!=0;roll++){
        if( (a>>roll)%2!=0&&(b>>roll)%2==0){
            max_roll = roll;
        }
    }
    m = min(m,(1<<max_roll)-(b%(1<<max_roll))+(a%((1<<max_roll)))+1);

    int higher_bit=max_roll+1;
    while(!((b>>higher_bit)%2==1&&(a>>higher_bit)%2==0 ) ){
        higher_bit++;
    }
    int moves=0;
    if(b==(1<<higher_bit)){
        m = min(m,(1<<higher_bit)-a%(1<<higher_bit));
    }else{


    }
    m = min(m,moves);
    cout << m << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
