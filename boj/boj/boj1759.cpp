//
//  boj1759.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2023/01/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alpha;
int l,c;
string s="";

void dfs(int depth,int idx) {
    if(depth==l) {
        int cnt1=0, cnt2=0;    //모음, 자음 count
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cnt1++;
            else cnt2++;
        }
        
        if(cnt1>=1 && cnt2>=2) cout << s << '\n';
        return;
    }
    
    for(int i=idx;i<c;i++) {
 
        if(s.back()<alpha[i] || s=="") s+=alpha[i];
        else continue;
        
        dfs(depth+1,idx+1);
        s.pop_back();
        
    }
}

int main() {
    cin >> l >> c;

    for(int i=0;i<c;i++) {
        char c;
        cin >> c;
        alpha.push_back(c);
    }
    
    sort(alpha.begin(),alpha.end());
    
    dfs(0,0);
}
//
//암호: 서로 다른 L개의 알파벳 소문자/최소 한개 a,e,i,o,u/최소 두개 자음/오름차순 정렬
//조교 사용 예상 문자 종류 c가지 -> 가능성 있는 암호 구하기, 오름차순 정렬
