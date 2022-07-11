//
//  boj10828.cpp
//  boj
//
//  Created by 다곰 on 2022/07/11.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    stack <int> s;
    
    cin >> n;
    cin.ignore();
    
    string str;
    for (int i=0; i <n; i++) {
        
        getline(cin,str);
        
        //push
        if(str[1]=='u') {
            //숫자 분리
            int num = stoi(str.substr(5));
            s.push(num);
        }
        //pop
        else if(str=="pop") {
            if(s.empty()) cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        //size
        else if(str=="size") {
            cout << s.size() << endl;
        }
        //empty
        else if(str=="empty") {
            if(s.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        //top
        else if(str=="top"){
            if(s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
        
    }
    
    
}
