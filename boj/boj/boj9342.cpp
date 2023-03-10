//
//  boj9342.cpp
//  boj
//  memory: 2176 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/10.
//

#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    regex re("(^[A-F]?A+F+C+[A-F]?$)");
    
    while (n--) {
        string s;
        cin >> s;
        if (regex_match(s,re)==0) cout << "Good\n";
        else cout << "Infected!\n";
    }
}
