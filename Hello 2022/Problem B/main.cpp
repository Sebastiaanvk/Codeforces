#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int left=INT_MAX;
    int right=INT_MIN;
    int index_left, index_right, price_left, price_right;
    int current_price;
    bool overlapping=false;
    int cheapest_overlapping;
    for(int i=0; i<n; i++){
        int new_left, new_right, new_price;
        cin >> new_left >> new_right >> new_price;
        if(new_left<left ){
                left=new_left;
                index_left=i;
                price_left=new_price;
                overlapping=false;
        } else if((new_left==left&&new_price<price_left )){
                left=new_left;
                index_left=i;
                price_left=new_price;
        }

        if(new_right>right){
                right=new_right;
                index_right=i;
                price_right=new_price;
                overlapping=false;
        } else if(new_right==right&&new_price<price_right){
                right=new_right;
                index_right=i;
                price_right=new_price;
        }

        if(new_left==left&&new_right==right){
            if(overlapping){
                cheapest_overlapping = min(cheapest_overlapping,new_price);
            } else {
                overlapping = true;
                cheapest_overlapping = new_price;
            }
        }
        if(overlapping){
            current_price=min(cheapest_overlapping,price_left+price_right);
        } else {
            current_price=price_left+price_right;
        }
        cout << current_price << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for( int i=0; i<t; i++){
        solve();
    }
    return 0;
}
