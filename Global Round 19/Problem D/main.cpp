#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Pa{
    int a;
    int b;
};

bool operator<(const Pa& p1, const Pa&p2){
    return abs(p1.a-p1.b)>abs(p2.a-p2.b);
}

void solve(){
    int n;
    cin >> n;
    vector<Pa> v(n);
    int total_sum=0;

    for(int i=0;i<n;i++){
        cin >> v[i].a;
        total_sum += v[i].a;
    }
    for(int i=0;i<n;i++){
        cin >> v[i].b;
        total_sum += v[i].b;
    }

//    bool something_swapped = true;
//    int diff = 0;//Sum(A)-Sum(B);
//    for(int i=0;i<n;i++) diff += v[i].a-v[i].b;
//    while(something_swapped){
//        something_swapped = false;
//        for(int i=0;i<n;i++){
//            if( abs(diff+2*v[i].b-2*v[i].a)<abs(diff) ){
//                something_swapped = true;
//                diff += 2*v[i].b-2*v[i].a;
//                swap(v[i].a,v[i].b);
//            }
//        }
//    }

    vector<set<int>> sets(n+1);
    sets[0] = {0};
    for(int i=1;i<=n;i++){
        for(auto x:sets[i-1]){
            sets[i].insert(x+v[i-1].a);
            sets[i].insert(x+v[i-1].b);
        }
    }
    long long closest_to_half ;
    long long min_diff = total_sum;
    for(auto x:sets[n]){
        if( abs(total_sum-2*x)<min_diff ){
            closest_to_half = x;
            min_diff = abs(total_sum-2*x);
        }
    }

    long long sum_of_squares = 0;
    for(int i=0; i<n; i++){
        sum_of_squares += v[i].a*v[i].a+v[i].b*v[i].b;
    }
    cout << (n-2)*sum_of_squares+closest_to_half*closest_to_half+(total_sum-closest_to_half)*(total_sum-closest_to_half) << '\n';

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
