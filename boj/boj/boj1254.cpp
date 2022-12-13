//
//  boj1254.cpp
//  boj
//  memory: 2024 KB
//  time: 0 ms
//  Created by 다곰 on 2022/12/13.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int siz=s.size();
    
    //int k=-1;
    
    int l=-1, r=-1;
    while(1) {
        if(siz==s.size()*2-1) break;
        
        if(siz%2==0) {
            l=siz/2-1;
            r=siz/2;
        }
        else {
            l=siz/2-1;
            r=siz/2+1;
        }
        int c=s.size()-r;
//        cout << s.substr(l-c+1,l) << endl;
//        cout << s.substr(r,c) << endl;
        string sr=s.substr(r,c);
        reverse(sr.begin(), sr.end());
        if(s.substr(l-c+1,c)==sr) break;
        siz++;
        
    }
    
    cout << siz << endl;
}
/*
일단 반으로 나눠서 팰린드롬인지 검사
아니라면 기준점을 뒤로 해보기
기준 뒤로 했을 때 기준점 +n, -n 자리가 같으면 팰린드롬 가능하다고 판단하고 부족한 단어 개수+기존 단어 길이 return
*/
