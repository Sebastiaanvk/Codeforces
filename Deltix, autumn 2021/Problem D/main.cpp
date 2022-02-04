#include <iostream>
#include <set>
#include <heap>

using namespace std;

struct Set_and_size{
    int set_id;
    int set_size;
};

bool operator<(const Set_and_size& s1, const Set_and_size& s2){
    return s2.set_size<s1.set_size;
}

int main()
{
    int n, d;
    cin >> n >> d;
    int in_set[n+1] = {0};
    int nr_sets=0;
    int set_size[n+1] = {0};
    int extra_meeting=0;
    for(int i=0; i<d; i++){
        int x, y;
        cin >> x >> y;
        if(in_set[x]==0&&in_set[y]==0){
            nr_sets++;
            in_set[x]=nr_sets;
            in_set[y]=nr_sets;
            set_size[nr_sets] = 2;
        } else if(in_set[x]==0){
            in_set[x] = in_set[y];
            set_size(in_set[y])++;
        } else if(in_set[y]==0){
            in_set[y] = in_set[x];
            set_size(in_set[x])++;
        } else if(in_set[x]==in_set[y]){
            extra_meeting++;
        } else {
            int leave_set = in_set[y];
            for(int p=1; p<=n; p++){
                if(in_set[p]==leave_set){
                    in_set[p]=in_set[x];
                    set_size[in_set[x]]++;
                }
            }
            set_size[leave_set] = 0;
        }



    }
    return 0;
}
