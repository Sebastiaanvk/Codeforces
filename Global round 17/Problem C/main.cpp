#include <iostream>
#include <vector>

using namespace std;




int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> as;
        vector<int> bs;
        int a,b;
        for(int j=0; j<n; j++){
            cin >> b >> a;
            as.push_back(a);
            bs.push_back(b);
        }
        vector<int> max_richer;
        int highest_k=1;
        int arr[n][n+1] = {0};
        for(int j=0;j<n;j++){
            arr[j][0]=INT_MAX;
            arr[j][1] = bs[j];
        }

        for(int guest=1;guest<n;guest++){
            for(int k=1; k<=guest+1 ; k++ ){
                int max_with_guest = min(bs[guest],arr[guest-1][k-1]-1);
                if(k-1<=as[guest] && arr[guest-1][k-1]!=0&&max_with_guest>arr[guest-1][k]){
                    highest_k = max(highest_k,k);
                    arr[guest][k]=max_with_guest;
                } else {
                    arr[guest][k]=arr[guest-1][k];
                }
            }
        }
        cout << highest_k << endl;

    }
    return 0;
}
