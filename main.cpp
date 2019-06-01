#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<set>

using namespace std;

int main(void) {
    string str;

    cout << "give a string" << endl;
    getline(cin, str); 
    cout << str;

    int num;
    cout << endl << "please give size: " << endl;
    cin >> num;

    cout << "please give number: " << endl;
    int *p = new int[num];
    for(int i=0;i<num;i++) {
        cin >> p[i];
    }

    for (int i=0; i< num; i++) {
        cout << p[i] << "-";
    }

    vector<int> a(10);
    for(int i=0;i<10;i++) {
        a.push_back(i);
    }
    cout << endl;

    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    while (!st1.empty()) {
        cout << "pop" << st1.top() << endl;
        st1.pop();
    }

    set<int> set1;
    set1.insert(1);

    map<int, string> studentMap;
    map<int, string>::iterator iter;
    studentMap[0] = "Jack Wang";
    studentMap[1] = "Tony Bell";

    for(iter = studentMap.begin(); iter != studentMap.end(); iter++) {
        cout << iter->first << iter->second << endl;
    }

    return 0;
}
