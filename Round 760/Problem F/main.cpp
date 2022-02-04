#include <iostream>
#include <vector>

using namespace std;


int main()
{
    long long x,y;
    cin >> x >> y;

    if(x==y){
        cout << "YES\n";
        return 0;
    }
    if(y%2==0){
        cout << "NO\n";
        return 0;
    }

    vector<int> y_bin_rep,x_bin_rep;
    int current_length = 0;
    while(y!=0){
        int n = y%2;
        current_length++;
        y/=2;
        if( (y%2 != n) ){
            y_bin_rep.push_back(current_length);
            current_length = 0;
        }
    }
    current_length=0;
    while(x!=0){
        int n = y%2;
        current_length++;
        x/=2;
        if( (x%2 != n) ){
            x_bin_rep.push_back(current_length);
            current_length = 0;
        }
    }
    if(x_bin_rep.size()==y_bin_rep.size()-1){
        bool normal_same = true;
        for(int i=0; i<x_bin_rep.size()-1; i++){
            if(x_bin_rep[i]!=y_bin_rep[i+1]){
                normal_same = false;
            }
        }
        if(normal_same && x_bin_rep[x_bin_rep.size()-1]<=y_bin_rep[y_bin_rep.size()-1]){
            cout << "YES\n" << endl;
        }

        bool mirrored_same = true;
        for(int i=0; i<x_bin_rep.size()-1; i++){
            if(x_bin_rep[x_bin_rep.size()-1-1-i]!=y_bin_rep[i+1]){
                mirrored_same = false;
            }
        }
        if(mirrored_same && x_bin_rep[x_bin_rep.size()-1]<=y_bin_rep[0]){
            cout << "YES\n" << endl;
            return 0;
        }

    } else if( x_bin_rep.size()==y_bin_rep.size()-1 ){
        bool normal_same = true;
        for(int i=1; i<x_bin_rep.size()-1; i++){
            if(x_bin_rep[i]!=y_bin_rep[i]){
                normal_same = false;
            }
        }
        if(normal_same && x_bin_rep[x_bin_rep.size()-1]<=y_bin_rep[y_bin_rep.size()-1] && x_bin_rep[0]<=y_bin_rep[0]){
            cout << "YES\n" << endl;
            return 0;
        }

        bool mirrored_same = true;
        for(int i=1; i<x_bin_rep.size()-1; i++){
            if(x_bin_rep[x_bin_rep.size()-1-i]!=y_bin_rep[i]){
                mirrored_same = false;
            }
        }
        if(mirrored_same && x_bin_rep[x_bin_rep.size()-1]<=y_bin_rep[0]&&x_bin_rep[0]<=y_bin_rep[x_bin_rep.size()-1]){
            cout << "YES\n" << endl;
            return 0;
        }
    } else {
        cout << "NO\n";
    }


    return 0;
}
