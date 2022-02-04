#include <iostream>
#include <vector>

using namespace std;

const char B = 'B';
const char W = 'W';

void solve(){
    int n,m;
    int r,c;
    cin >> n >>m >> r >>c;
    bool in_row_or_col = false;
    bool contains_b = false;
    bool already_b = false;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(char c:s){
            if(c==B){
                contains_b=true;
            }
            if(i==r-1&&c==B){
                in_row_or_col=true;
            }
        }
        if(i==r-1&&s[c-1]==B){
            already_b=true;
        }

        if(s[c-1]==B){
            in_row_or_col=true;
        }
    }
    if(!contains_b){
        cout << -1 << endl;
    }else if(already_b){
        cout << 0 << endl;
    } else if(in_row_or_col){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
