#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input("text.txt");
    int n;
    input >> n;
    for(int i=0; i<n; i++){
        cout << i << endl;
    }

    set<int> s;
    s.insert(5);
    s.insert(7);
    set<int>::iterator it ;
    for(it = s.begin();it!=s.end();it++){
        cout << *it << endl;
    }


    return 0;
}
