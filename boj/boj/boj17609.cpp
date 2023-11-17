//
//  boj17609.cpp
//  boj
//  memory: 2596 KB
//  time: 20 ms
//  Created by 다곰 on 2023/10/04.
//

//#include <iostream>
//#include <string>
//using namespace std;
//
//int dfs(string s, int l, int r, int cnt) {
//
//    while(l<r) {
//        if(s[l]!=s[r]) {
//            if(cnt==0) {
//                if(dfs(s,l+1,r,1)==0 || dfs(s,l,r-1,1)==0 ) return 1;
//                return 2;
//            }
//            else return 2;
//        }
//        else {
//            l++;
//            r--;
//        }
//
//    }
//    return 0;
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    int t;
//    cin >> t;
//
//    while(t--) {
//        string s;
//        cin >> s;
//
//        cout << dfs(s,0,s.size()-1,0) << endl;
//    }
//
//}

/* 풀이 2 */
#include <iostream>
#include <string>
using namespace std;

bool dfs(string s, int l, int r) {
    if(l>r) return false;
    while(l<r) {
        if(s[l]==s[r]) {
            l++;
            r--;
        }
        else return false;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        int l=0,r=s.size()-1;
        
        int res=0;
        while(l<r) {
            if(s[l]==s[r]) {
                l++;
                r--;
            }
            else if(dfs(s,l+1,r) || dfs(s,l,r-1)) {
                res=1;
                break;
            }
            else {
                res=2;
                break;
            }
        }
        
        cout << res << '\n';
    }
}

/*
s는 0, e는 n-1 자리부터 탐색해서 s<e 범위 안에서 탐색
두 자리가 같으면 하나씩 이동해줌
두 자리가 틀리면 둘 중 하나를 옮겼을 때 dfs
*/
