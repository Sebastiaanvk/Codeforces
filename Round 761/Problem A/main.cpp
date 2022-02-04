#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        int freq[26] = {0};
        for( int j=0; j<s.size(); j++){
            freq[s[j]-'a']++;
        }
        string t;
        cin >> t;
        if(t=="abc"&&freq[0]!=0){
            for(int j=0; j<freq[0]; j++){
                cout << 'a';
            }
            for(int j=0; j<freq[2]; j++){
                cout << 'c';
            }
            for(int j=0; j<freq[1]; j++){
                cout << 'b';
            }
            for( int k=3;k<26; k++){
                for(int j=0; j<freq[k]; j++){
                    cout << static_cast<char>('a'+k);
                }
            }
        } else {
            for( int k=0;k<26; k++){
                for(int j=0; j<freq[k]; j++){
                    cout << static_cast<char>('a'+k);
                }
            }
        }
        cout << endl;
    }
    return 0;
}
