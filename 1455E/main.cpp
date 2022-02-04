#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    vector<int> xs ={0,0,0,0};
    vector<int> ys = {0,0,0,0};
    for(int i=0; i<tests; i++){
        for(int j=0; j<4; j++){
            cin >> xs[j] >> ys[j];
        }
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());
        int mindx = xs[2]-xs[1];
        int maxdx = xs[3]-xs[0];
        int mindy = ys[2]-ys[3];
        int maxdy = ys[3]-ys[0];

        int dist = xs[1]-xs[0]+xs[3]-xs[2]+ys[1]-ys[0]+ys[3]-ys[2];
        if(mindx>maxdy){
            dist+=2*(mindx-maxdy);
        }else if(mindy>maxdx){
            dist+=2*(mindy-maxdx);
        }
        cout << dist << endl;
    }


    return 0;
}
