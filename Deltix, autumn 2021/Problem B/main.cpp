#include <iostream>

using namespace std;

bool abc_at_loc(const string& s, const int& loc){
    if(s[loc]=='a'&&loc+2<s.size()){
        return s[loc+1]=='b'&&s[loc+2]=='c';
    } else if(s[loc]=='b'&&loc+1<s.size()&&loc-1>=0){
        return s[loc-1]=='a'&&s[loc+1]=='c';
    } else if(s[loc]=='c'&&loc-2>=0){
        return s[loc-2]=='a'&&s[ loc-1]=='b';
    }
    return false;
}

int main()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    int nr_of_abcs=0;
    for( int i=0; i+2<s.size(); i++){
        if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
            nr_of_abcs++;
        }
    }
    for( int i=0; i<q; i++){
        int loc;
        char c;
        cin >> loc >> c;
        loc--;
        if(abc_at_loc(s,loc)) nr_of_abcs--;
        s[loc]=c;
        if(abc_at_loc(s,loc)) nr_of_abcs++;
        cout << nr_of_abcs << endl;
    }

    return 0;
}
