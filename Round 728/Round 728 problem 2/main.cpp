#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Numb{
    long long index;
    long long x;
};

bool operator<(const Numb& n1, const Numb& n2){
    return n1.x<n2.x;
}

bool operator==(const Numb& n1, const Numb& n2){
    return n1.x==n2.x;
}

int main()
{
    long long t;
    cin >> t;
    for(long long k=0;k<t;k++){

        long long n;
        cin >> n;
        vector<Numb> v;
        for(long long j=1; j<=n; j++){
            long long x;
            cin >> x;
            v.push_back({j,x});
        }
        sort(v.begin(),v.end());
        long long total = 0;
        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n&&v[i].x*v[j].x<=2*n;j++){
                if(v[i].x*v[j].x==v[i].index+v[j].index){
                    total++;
                }
            }
        }
        cout << total << endl;
    }


    return 0;
}
