//
//  strjoin.cpp
//  jmb
//
//  Created by 다곰 on 2022/03/07.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int c;
    cin >> c;
    while (c--) {
        vector<pair<int,int>> v;
        int sum=0, com=0,n;
        
        cin >> n;
        int inpt;
        for ( int i = 0; i < n; i++) {
            cin>> inpt;
            v.push_back(pair<int,int>(inpt,0));
        }
        
        while (v.size()>1) {
            sort(v.begin(),v.end());    //오름차순 정렬
            com =v[0].first + v[1].first;   //작은 숫자끼리 더해주기?
            sum += com;
            v.push_back(pair<int,int>(com,1));
            v.erase(v.begin(), v.begin()+2);
        }

        cout << sum << endl;

    }
    
}
