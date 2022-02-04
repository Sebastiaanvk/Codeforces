#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    int message;
    int watches;
};

struct Message{
    int id;
    int watches;
};

bool operator<(const Message& m1, const Message& m2){
    return m1.watches<m2.watches;
}

bool operator==(const Message& m1, const Message& m2){
    return m1.watches==m2.watches;
}

int main()
{
    int n;
    cin >> n;
    vector<Student> students;
    int max_message=0;
    for(int i=0;i<n;i++){
        Student s;
        cin >> s.message >> s.watches;
        students.push_back(s);
        if(s.message>max_message) max_message=s.message;
    }

    int max_t;

    vector<int> messages_in_best;
    long long max_num=0;
    long long max_denom=1;



    vector<int> message_watches;
    message_watches.resize(max_message+1);

    for(int t=1; t<20; t++){
        for(int i=0;i<max_message+1;i++){
            message_watches[i]=0;
        }
        for(int i=0;i<students.size(); i++){
            message_watches[students[i].message] += min(t,students[i].watches);
        }
        vector<Message> mess;
        for(int i=0;i<max_message;i++){
            mess.push_back({i,message_watches[i]});
        }

        sort(mess.begin(),mess.end());
        long long num=0;
        long long den=t;
        for(int i=0;i<t; i++){
            num+=mess[i].watches;
        }
        if(num*max_denom>max_num*den){
            max_num = num;
            max_denom = den;
            max_t=t;
            messages_in_best.clear();
            for(int i=0;i<t;i++){
                messages_in_best.push_back(mess[i].id);
            }
        }
    }
    vector<Message> mess;
    for(int i=0;i<max_message+1;i++){
            message_watches[i]=0;
        }
    for(int i=0;i<students.size(); i++){
        message_watches[students[i].message] += students[i].watches;
    }

    for(int i=0;i<max_message;i++){
        mess.push_back({i,message_watches[i]});
    }

    sort(mess.begin(),mess.end());

    for(int t=20;t<+n;t++){
        long long num=0;
        long long den=t;

        for(int i=0;i<t; i++){
            num+=mess[i].watches;
        }
        if(num*max_denom>max_num*den){
            max_num=num;
            max_denom = den;
            max_t=t;
            messages_in_best.clear();
            for(int i=0;i<t;i++){
                messages_in_best.push_back(mess[i].id);
            }
        }
    }

    cout << max_t << endl;
    cout << messages_in_best[0];
    for(int i=1; i<max_t; i++){
        cout  << " "<<messages_in_best[i] ;
    }
    cout << endl;


    return 0;
}
