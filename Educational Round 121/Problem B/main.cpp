#include <iostream>

using namespace std;

void solve(){
    string s;
    cin >> s;
    for(int i=s.size()-1;i>0;i--){
        if(s[i]-'0'+s[i-1]-'0'>=10){
            int x = s[i]-'0'+s[i-1]-'0';
            s[i]=x%10+'0';
            s[i-1]=x/10+ '0';
            cout << s << endl;
            return;
        }
    }
    s[1] = s[0]-'0'+s[1];
    for(int i=1; i<s.size(); i++){
        cout << s[i];
    }
    cout << endl;

//    cin >> x;
//    int p=1;
//    while(x/p>=10){
//        if( ((x/p)%10)+ ((x/(10*p) )%10) >=10){
//            cout << x-((x/(10*p) )%10)*10*p+((x/(10*p) )%10)*p << endl;
//            return;
//        }
//        p*=10;
//    }
//    cout << (x/p)*p/10+x%p << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
