#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    fill(v.begin(),v.end(),0);
    int i=1;
    while(i<=n){
        printf("? %d\n",i);
        fflush(stdout);
        int start;
        cin >> start;
        int last=start;
        int current;
        printf("? %d\n",i);
        fflush(stdout);
        cin >> current;
        while(current!=start){
            v[last]=current;
            last=current;
            printf("? %d\n",i);
            fflush(stdout);
            cin >> current;
        }
        v[last]=current;
        while(i<=n&&v[i]!=0){
            i++;
        }
    }
    printf("!");
    fflush(stdout);
    for(int j=1;j<=n;j++){
        printf(" %d",v[j]);
        fflush(stdout);
    }
    cout << endl;
    fflush(stdout);

}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
