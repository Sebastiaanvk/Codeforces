#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int max_diff=-1;
    int h;
    int min_diff=INT_MAX;
    for(int i=3; i<=n; i++){
        printf("? %d %d %d\n",1,2,i);
        fflush(stdout);
        int diff;
        cin >> diff;
        if(diff>max_diff){
            max_diff = diff;
            h = i;
        }
        if(diff<min_diff){
            min_diff = diff;
        }
    }
    int new_max_diff = -1;
    int new_max_h;
    for(int i=3; i<=n; i++){
        if(i!=h){
            printf("? %d %d %d\n",1,h,i);
            fflush(stdout);
            int diff;
            cin >> diff;
            if(diff>new_max_diff){
                new_max_diff = diff;
                new_max_h = i;
            }
        }
    }
    if(new_max_diff>max_diff){
        printf("! %d %d\n",h,new_max_h);
        fflush(stdout);
    } else if(new_max_diff==max_diff){
        printf("! %d %d\n",h,1);
        fflush(stdout);
    } else if(min_diff==max_diff){
         printf("! %d %d\n",1,2);
    }else {
        printf("! %d %d\n",h,2);
        fflush(stdout);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
