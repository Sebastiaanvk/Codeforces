#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Group{
    long long sum;
    long long nr_students;
    vector<long long> students;
};

struct Avg{
    long long sum;
    long long nr;
};

bool operator<(const Avg& a, const Avg& b){
    return a.sum*b.nr<b.sum*a.nr;
}

bool operator==(const Avg& a, const Avg& b){
    return a.sum*b.nr==b.sum*a.nr;
}

bool match_possible(const multiset<Avg>& averages, const vector<long long>& teachers){
    long long index=0;
    for(Avg a:averages){
        if( a.sum>teachers[index]*a.nr ){
            return false;
        }
        index++;
    }
    return true;
}

void solve(){
    long long n,m;
    cin >> n >> m;
    vector<long long> teachers;
    for(long long i=0; i<n; i++){
        long long x;
        cin >> x;
        teachers.push_back(x);
    }
    sort(teachers.begin(),teachers.end());
    if(n>m){
        teachers.erase(teachers.begin(),teachers.begin()+(n-m) );
    }
    vector<Group> groups;
    for(long long i=0; i<m; i++){
        Group g;
        g.sum=0;
        cin >> g.nr_students;
        for(long long j=0; j<g.nr_students; j++){
            long long x;
            cin >> x;
            g.sum += x;
            g.students.push_back(x);
        }
        groups.push_back(g);
    }
    multiset<Avg> averages;
    for(long long i=0; i<m; i++){
        averages.insert( {groups[i].sum,groups[i].nr_students} );
    }
    for( long long i=0; i<m; i++){
        averages.erase( averages.lower_bound({groups[i].sum,groups[i].nr_students}) );
        for( long long j=0; j<groups[i].nr_students; j++){
            averages.insert( { groups[i].sum-groups[i].students[j] ,groups[i].nr_students-1} );
            if(match_possible(averages,teachers)){
                cout << "1";
            } else {
                cout << "0";
            }
            averages.erase( averages.lower_bound({ groups[i].sum-groups[i].students[j] ,groups[i].nr_students-1}) );
        }
        averages.insert({groups[i].sum,groups[i].nr_students});
    }
    cout << endl;
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
