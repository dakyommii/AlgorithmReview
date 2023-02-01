//
//  boj1339.cpp
//  boj
//  memory: 2212 KB
//  time: 0 ms
//  Created by 다곰 on 2023/02/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int alpha[26]={0,};
    while(n--) {
        string s;
        cin >> s;
        
        int k=s.size()-1;
        for(int i=0;i<s.size();i++) {
            int c=s[i]-'A';
            alpha[c]+=pow(10,k);
            k--;
        }
     }
    
    sort(alpha, alpha+26, greater<int>());
    
    int k=9;
    int ans=0;
    for (int i=0; i<26; i++) {
        if (alpha[i]!=0) {
            ans+=alpha[i]*k;
            k--;
        }
    }
    
    cout << ans << endl;

}

//n 개의 단어/알파벳 대문자로만 구성
//알파벳 대문자를 0~9까지 숫자 중 하나로 바꿔서 n개의 수를 모두 합하는 문제
//가장 많이 등장하는 숫자일수록 높은 숫자로 지정 -> map으로 각 알파벳 개수 count
