#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> abc_min_removed = {0};
    vector<int> ab_min_removed = {0};
    vector<int> a_min_removed = {0};
    if(s[0]=='a') a_min_removed[0]=1;
    for(int i=1; i<n; i++){
        if(s[i]=='a'){
            a_min_removed.push_back(a_min_removed[i-1]+1);
            ab_min_removed.push_back(ab_min_removed[i-1]);
            abc_min_removed.push_back(abc_min_removed[i-1]);
        } else if(s[i]=='b'){
            a_min_removed.push_back(a_min_removed[i-1]);
            ab_min_removed.push_back(min(ab_min_removed[i-1]+1,a_min_removed[i-1]) );
            abc_min_removed.push_back(abc_min_removed[i-1]);
        } else {
            a_min_removed.push_back(a_min_removed[i-1]);
            ab_min_removed.push_back(ab_min_removed[i-1]);
            abc_min_removed.push_back( min(abc_min_removed[i-1]+1,ab_min_removed[i-1]) );
        }
        /*
        cout << a_min_removed[i] << endl;
        cout << ab_min_removed[i] << endl;
        cout << abc_min_removed[i] << endl;*/
    }

    for( int i=0; i<q; i++){
        int loc;
        char c;
        cin >> loc >> c;
        loc--;
        s[loc]=c;
        if(loc==0){
            if(c=='a'){
                a_min_removed[0]=1;
            } else {
                a_min_removed[0]=0;
            }
        }
        for(int i=max(1,loc); i<n; i++){
            if(s[i]=='a'){
                a_min_removed[i] = a_min_removed[i-1]+1;
                ab_min_removed[i] = ab_min_removed[i-1];
                abc_min_removed[i] = abc_min_removed[i-1];
            } else if(s[i]=='b'){
                a_min_removed[i] = a_min_removed[i-1];
                ab_min_removed[i] = min(ab_min_removed[i-1]+1,a_min_removed[i-1]) ;
                abc_min_removed[i] = abc_min_removed[i-1];
            } else {
                a_min_removed[i] = a_min_removed[i-1];
                ab_min_removed[i] = ab_min_removed[i-1];
                abc_min_removed[i] =  min(abc_min_removed[i-1]+1,ab_min_removed[i-1]) ;
            }
        }
        cout << abc_min_removed[n-1] << endl;
    }
    return 0;
}
