//
//  boj1755.cpp
//  boj
//  memory: 2028 KB
//  time: 0 ms
//  Created by 다곰 on 2022/12/13.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string alpha[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int m,n;
    
    cin >> m >> n;
    map<string,int> mp;
    for(int i=m;i<=n;i++) {
        string str="";
        
        // 두자리 수
        if(i/10!=0) {
            str=alpha[i/10];
            str+=" ";
        }
        // 한자리수
        str+=alpha[i%10];
        
        mp.insert({str,i});
    }
    
    for(auto it:mp) {
        cout << it.second << endl;
    }
}
