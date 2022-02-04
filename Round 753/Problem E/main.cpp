#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,m;
        cin >> n;
        cin >> m;
        string commands;
        cin >> commands;

        int min_x=0;int max_x=0; int min_y=0; int max_y=0;
        int current_x=0;
        int current_y=0;
        int j=0;
        bool cont = true;
        while( j<commands.length() && cont){
            char c = commands[j];
            if(c=='D'){
                current_y += 1;
                if(current_y>max_y){
                    if(current_y-min_y>=n){
                        cont = false;
                    } else {
                        max_y=current_y;
                    }
                }
            } else if(c=='U'){
                current_y-=1;
                if(current_y<min_y){
                    if(max_y-current_y>=n){
                        cont = false;
                    } else {
                        min_y=current_y;
                    }
                }
            } else if(c=='R'){
                current_x+=1;
                if(current_x>max_x){
                    if(current_x-min_x>=m){
                        cont = false;
                    } else {
                        max_x=current_x;
                    }
                }
            } else {
                current_x-=1;
                if(current_x<min_x){
                    if(max_x-current_x>=m){
                        cont = false;
                    } else {
                        min_x=current_x;
                    }
                }
            }
        j++;
        }
        cout << 1-min_y << " " << 1-min_x << endl;
    }
    return 0;
}
