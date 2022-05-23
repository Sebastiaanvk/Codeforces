#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    unsigned long long x;
    cin >> x;

    unsigned long long goal = 1;
    for(int i=1; i<n; i++){
        goal *= 10;
    }
    if(n>=goal){
        cout << 0 << '\n';
        return;
    }

    unordered_map<unsigned long long, int> steps_to_get;
    queue<unsigned long long > Q;
    Q.push(x);
    steps_to_get[x] = 0;
    while(!Q.empty()){
        unsigned long long next = Q.front();
        Q.pop();
        unsigned long long cpy = next;
        vector<bool> digits (10,false);
        while(cpy!=0){
            int d = cpy%10;
            cpy /= 10;
            if(!digits[d]){
                digits[d]=true;
                unsigned long long add_next = next*d;
                if(add_next>=goal){
                    cout << steps_to_get[next]+1 << '\n';
                    return;
                }
                if(steps_to_get.count(add_next)==0){
                    steps_to_get[add_next] = steps_to_get[next]+1;
                    Q.push(add_next);
                }
            }
        }
    }
    cout << -1 << '\n';
}

int main()
{
    solve();
    return 0;
}
