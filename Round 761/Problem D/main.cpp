#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void find_impostors(){
    int n;
    cin >> n;
    bool impostor_triple_found = false;
    bool crew_triple_found = false;

    int index=1;
    int impostor_triple_ind,crew_triple_ind;

    while(!(impostor_triple_found&&crew_triple_found)){
        //cout << "? " << index << " " << index+1 << " " << index+2 << endl;
        printf("? %d %d %d\n",index,index+1,index+2);
        fflush(stdout);
        int r;
        cin >> r;
        if(r==0&&!impostor_triple_found){
            impostor_triple_found=true;
            impostor_triple_ind=index;
        }
        if(r==1&&!crew_triple_found){
            crew_triple_found = true;
            crew_triple_ind=index;
        }
        index+=3;
    }
    int r_d,r_e;
//    cout << "? " << impostor_triple_ind << " " << impostor_triple_ind+1 << " " << crew_triple_ind << endl;
//    cout.flush();
    printf("? %d %d %d\n",impostor_triple_ind,impostor_triple_ind+1,crew_triple_ind);
    fflush(stdout);
    cin >> r_d;
//    cout << "? " << impostor_triple_ind << " " << impostor_triple_ind+1 << " " << crew_triple_ind+1 << endl;
//    cout.flush();
    printf("? %d %d %d\n",impostor_triple_ind,impostor_triple_ind+1,crew_triple_ind+1);
    fflush(stdout);
    cin >> r_e;

    int confirmed_impostor,confirmed_crew;
    if(r_d==1&&r_e==1){
        confirmed_impostor = impostor_triple_ind+2;
        confirmed_crew = crew_triple_ind;
    } else if(r_d==0&&r_e==1){
        confirmed_impostor = crew_triple_ind;
        confirmed_crew = crew_triple_ind+1;
    } else if(r_d==1&&r_e==0){
        confirmed_impostor = crew_triple_ind+1;
        confirmed_crew = crew_triple_ind;
    } else if(r_d==0&&r_e==0){
        confirmed_impostor = impostor_triple_ind;
//        cout << "? " << impostor_triple_ind << " " << crew_triple_ind << " " << crew_triple_ind+1 << endl;
//        cout.flush();
        printf("? %d %d %d\n",impostor_triple_ind,crew_triple_ind,crew_triple_ind+1);
        fflush(stdout);
        int r;
        cin >> r;
        if(r==1){
            confirmed_crew = crew_triple_ind;
        } else {
            confirmed_crew = crew_triple_ind+2;
        }
    }
    vector<int> impostors = {confirmed_impostor};
    for(int i=1; i<=n; i++){
        if(i!=confirmed_impostor&&i!=confirmed_crew){
//            cout << "? " << confirmed_impostor << " " << confirmed_crew << " " << i << endl;
//            cout.flush();
            printf("? %d %d %d\n",confirmed_impostor,confirmed_crew,i);
            fflush(stdout);
            int r;
            cin >> r;
            if(r==0){
                impostors.push_back(i);
            }
        }
    }
//    cout << "! " << impostors.size();
    printf("! %d",impostors.size());
    fflush(stdout);
    for( int i=0; i<impostors.size(); i++){
//        cout << " " << impostors[i];
        printf(" %d",impostors[i]);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        find_impostors();
    }
    return 0;
}
