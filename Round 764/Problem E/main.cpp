#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Substring{
    int l;
    int r;
    int i;
};

void solve(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,Substring> substrings;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int l=1;l<=s.size()-1;l++){
            int r=l+1;
            int number=11*(s[l-1]-'0'+1)+(s[r-1]-'0'+1);
            substrings[number] = {l,r,i};
            r++;
            if(r<=s.size()){
                number = 11*number+(s[r-1]-'0'+1);
                substrings[number] = {l,r,i};
            }
        }
    }
    string s;
    cin >> s;
    if(m==1){
        cout << -1 << '\n';
        return;
    }
    vector<int> lengths;
    lengths.resize(s.size()+1);
    vector<bool> v(s.size()+1, false);
    v[0]=true;
    if( substrings.count( (s[0]-'0'+1)*11+s[1]-'0'+1) ){
        v[2]=true;
        lengths[2]=2;
    }
    for(int i=3;i<=s.size();i++){
        if( substrings.count( (s[i-2]-'0'+1)*11+s[i-1]-'0'+1 )&&v[i-2] ){
            v[i]=true;
            lengths[i]=2;
        } else if( substrings.count( (s[i-3]-'0'+1)*121+(s[i-2]-'0'+1)*11+s[i-1]-'0'+1)&&v[i-3] ){
            v[i]=true;
            lengths[i]=3;
        }
    }
    if(v[s.size()]){
        int t=s.size();
        vector<Substring> w;
        while(t>0){
            if(lengths[t]==2){
                w.push_back( substrings[(s[t-2]-'0'+1)*11+s[t-1]-'0'+1] );
                t -= 2;
            } else {
                w.push_back( substrings[(s[t-3]-'0'+1)*121+(s[t-2]-'0'+1)*11+s[t-1]-'0'+1] );
                t-= 3;
            }
        }
        cout << w.size() << '\n';
        for(int i=w.size()-1;i>=0;i--){
            printf("%d %d %d\n",w[i].l,w[i].r,w[i].i);
        }
    } else {
        cout << -1 << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
