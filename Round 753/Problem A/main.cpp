#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int positions[26];
    for( int i=0;i<t; i++){
        for(int loc=0;loc<26;loc++){
            char c;
            cin >> c;
            positions[c-'a']=loc;
        }
        string s;
        cin >> s;
        int total=0;
        int current_loc=positions[s[0]-'a'];
        for(int j=1; j<s.length(); j++){
            total += abs(current_loc-positions[ s[j]-'a' ]);
            current_loc = positions[ s[j]-'a' ];
        }
        cout << total << endl;
    }

    return 0;
}
