#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product{
    long long amount_needed;
    long long amount_before_discount;
    long long bought;
};

bool operator<(const Product& p1, const Product& p2){
    return p1.amount_before_discount<p2.amount_before_discount;
}

bool operator==(const Product& p1, const Product& p2){
    return p1.amount_before_discount==p2.amount_before_discount;
}


int main()
{
    int n;
    cin >> n;
    vector<Product> v;
    for(int i=0;i<n;i++){
        Product p;
        cin >> p.amount_needed;
        cin >> p.amount_before_discount;
        p.bought=0;
        v.push_back(p);
    }
    sort(v.begin(),v.end());

    int i=0;
    int j=n-1;
    long long money_spent=0;
    long long total_bought=0;
    while(i<j){

        if(total_bought>=v[i].amount_before_discount){
            money_spent += v[i].amount_needed-v[i].bought;
            total_bought += v[i].amount_needed-v[i].bought;
            i++;
        } else {
            if( v[i].amount_before_discount-total_bought>=v[j].amount_needed-v[j].bought ){
                money_spent += 2*(v[j].amount_needed-v[j].bought);
                total_bought += v[j].amount_needed-v[j].bought;
                j--;
            } else {
                money_spent += 2*(v[i].amount_before_discount-total_bought);
                v[j].bought += v[i].amount_before_discount-total_bought;
                total_bought += v[i].amount_before_discount-total_bought;

                if(v[j].bought==v[j].amount_needed){
                    j--;
                }
            }
        }
    }

    if( v[i].amount_needed>v[i].bought ){
        if(v[i].amount_before_discount>total_bought ){
            long long buy = min( v[i].amount_before_discount-total_bought,v[i].amount_needed-v[i].bought );
            money_spent += 2*buy;
            v[i].bought += buy;
            total_bought += buy;
        }
        if(v[i].bought<v[i].amount_needed){
            money_spent += v[i].amount_needed-v[i].bought;
        }
    }

    cout << money_spent;

    return 0;
}
