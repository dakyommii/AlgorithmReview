//
//  boj20210.cpp
//  boj
//  memory: 33128 KB
//  time: 500 ms
//  Created by 다곰 on 2023/10/12.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(vector<string>& v1, vector<string>& v2) {
    int len=min(v1.size(),v2.size());

    for(int i=0;i<len;i++) {
        
        if(v1[i]!=v2[i]) {
            // 숫자 비교
            
            if(v1[i][0]>='0'&&v1[i][0]<='9'&&v2[i][0]>='0'&&v2[i][0]<='9') {
                
                string s1="",s2="";
                
                for(int j=0;j<v1[i].size();j++) {
                    if(v1[i][j]!='0') {
                        s1=v1[i].substr(j);
                        break;
                    }
                    
                }
                
                for(int j=0;j<v2[i].size();j++) {
                    if(v2[i][j]!='0') {
                        s2=v2[i].substr(j);
                        break;
                    }
                    
                }
                
                if(s1==s2) return v1[i].size()<v2[i].size();
                else {
                    if(s1.size()<s2.size()) return true;
                    else if(s1.size()>s2.size()) return false;
                    else {
                        if(s1<s2) return true;
                        return false;
                    }
                }
                 
            }
            // 문자 vs 숫자
            if((v1[i][0]>='0'&&v1[i][0]<='9')||(v2[i][0]>='0'&&v2[i][0]<='9')){
                return v1[i]<v2[i];
            }


            if (toupper(v1[i][0]) == toupper(v2[i][0])) {
                return v1[i] < v2[i];
            }
            return toupper(v1[i][0]) < toupper(v2[i][0]);


        }
    }
    
    
    return v1.size()<v2.size();

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<string>> v;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        
        string tmp="";
        vector<string> vs;
        for(int j=0;j<s.size();j++) {
            // 숫자
            if(s[j]>='0'&&s[j]<='9') tmp+=s[j];
            else {
                if(tmp!="") vs.push_back(tmp);
                tmp=s[j];
                vs.push_back(tmp);
                tmp="";
            }
        }
        
        if(tmp!="") vs.push_back(tmp);
        v.push_back(vs);

    }
    
    
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].size();j++) {
            cout << v[i][j];
        }
        cout << endl;
    }

}
