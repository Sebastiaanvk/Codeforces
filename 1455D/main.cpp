#include <iostream>

using namespace std;

int main()
{
    int nr_lines;
    cin >> nr_lines;

    int arr [500];
    int length;

    int x;
    int sorted_left;
    int sorted_right;
    int index;

    int track_moves;

    for(int l=0; l<nr_lines; l++){
        cin >> length;
        cin >> x;
        for(int j=0; j<length; j++){
            cin >> arr[j];
        }

        sorted_left=0;

        while( sorted_left<length-1 && arr[sorted_left]<=arr[sorted_left+1] ){
            sorted_left++;
        }
        if(sorted_left==length-1){
            cout << 0 << endl;
            continue;
        }

        sorted_right=length-1;
        while( sorted_right>0 && arr[sorted_right-1]<=arr[sorted_right] ){
            sorted_right--;
        }

        index=0;
        while(index<length && arr[index]<=x){
            index++;
        }

        track_moves=0;

        while(true){
            track_moves+=1;
            swap(arr[index],x);
            if(sorted_left==index){
                while( sorted_left<length-1 && arr[sorted_left]<=arr[sorted_left+1] ){
                    sorted_left++;
                }
                if(sorted_left>=sorted_right){
                    cout << track_moves << endl;
                    break;
                }
            } else if(sorted_left<index){
                cout << -1 << endl;
                break;
            }
            while(index<length&&arr[index]<=x){
                index++;
            }
        }
    }


    return 0;
}
