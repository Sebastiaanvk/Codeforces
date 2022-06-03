#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Track{
    int id;
    int length;
};

bool operator<(const Track& t1, const Track& t2){
    if(t1.length==t2.length)
        return t1.id>t2.id;
    return t1.length>t2.length;
}

bool operator==(const Track& t1, const Track& t2){
    return t1.id==t2.id&&t1.length==t2.length;
}

void solve(){
    int n,m;
    cin >> n >> m;
    string s(m,'0');
    vector<int> lengths(m);
    priority_queue<Track> Q;
    for(int i=0; i<m; i++){
        s[i] = '1';
        cout << "? " << s << endl;
        cout.flush();
        cin >> lengths[i];
        Q.push({i,lengths[i]});
        s[i] = '0';
    }
    Track t = Q.top();
    Q.pop();
    s[t.id] = '1';
    int current_min = t.length;
    while(!Q.empty()){
        t = Q.top();
        Q.pop();
        s[t.id] = '1';
        cout << "? " << s << endl;
        cout.flush();
        int new_cap;
        cin >> new_cap;
        if(new_cap-current_min!=t.length){
            s[t.id] = '0';
        } else {
            current_min = new_cap;
        }
    }
    cout << "! " << current_min << endl;
    cout.flush();
}

int main()
{
    solve();
    return 0;
}
