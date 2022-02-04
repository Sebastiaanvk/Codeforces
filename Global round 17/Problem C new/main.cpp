#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> max_richer_people;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        int max_k=0;
        max_richer_people={INT_MAX};

        for(int j=0; j<n; j++){
            int a,b;
            cin >> a >> b;
            int start = max_k;
            if(b>=max_k&&max_richer_people[max_k]>0){
                max_richer_people.push_back( min(a,max_richer_people[max_k]-1) );
                max_k++;
            }
            for( int k=min(b+1,start); k>0&&k+n-1-j>max_k; k--){
                if( min(a,max_richer_people[k-1]-1)>max_richer_people[k] && max_richer_people[k-1]>0 ){
                    max_richer_people[k]=min(a,max_richer_people[k-1]-1);
                }
            }
        }
        cout << max_k << endl;
    }
    return 0;
}
