//
//  boj17219.cpp
//  boj
//
//  Created by 다곰 on 2022/10/28.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    string hp,pwd;
    unordered_map<string, string> um;
    while (n--) {
        cin >> hp >> pwd;
        um.insert({hp,pwd});
    }
    
    while (m--) {
        cin >> hp;
        cout << um[hp] << "\n";
    }
}
