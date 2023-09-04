//
//  boj20922.cpp
//  boj
//  memory: 7036 KB
//  time: 180 ms
//  Created by 다곰 on 2023/09/04.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    
    for(int i=0;i<n;i++) {
        cin >> num[i];
    }
    
    map<int,int> mp;

    int st=0,end=0;
    for(int i=0;i<n;i++){
        if(mp[num[i]]==k) break;
        end++;
        mp[num[i]]++;
    }
    
    int len=end-st;
    while(end<num.size()) {
        mp[num[st]]--;
        st++;
        
        while (end<num.size()) {
            if(mp[num[end]]==k) break;
            mp[num[end]]++;
            end++;
        }
        
        if(len<end-st) len=end-st;

    }
    
    cout << len << endl;
}


