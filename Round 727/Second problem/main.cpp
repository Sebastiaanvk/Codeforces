#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    int total=0;
    vector<int> v;
    v.push_back(0);
    char letter;
    for(int i=0; i<n; i++){
        cin >> letter;
        total += letter-'a'+1;
        v.push_back(total);
    }
    int x,y;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout << v[y]-v[x-1]<<endl;
    }
    return 0;
}
