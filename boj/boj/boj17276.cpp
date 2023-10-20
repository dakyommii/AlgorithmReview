//
//  boj17276.cpp
//  boj
//  memory: 5052 KB
//  time: 340 ms
//  Created by 다곰 on 2023/10/21.
//

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<vector<int>> clock1(vector<vector<int>> v) {
    int n=v.size();
    vector<vector<int>> tmp(n,vector<int>(v.size(),0));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) tmp[i][n/2]=v[i][j];
            else if(i==n/2) tmp[j][j]=v[i][j];
            else if(j==n/2) tmp[i][n-i-1]=v[i][j];
            else if((i+j)==n-1) tmp[n/2][j]=v[i][j];
            else tmp[i][j]=v[i][j];
        }
    }
    
    return tmp;
}

vector<vector<int>> clock2(vector<vector<int>> v) {
    int n=v.size();
    vector<vector<int>> tmp(n,vector<int>(v.size(),0));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) tmp[n/2][j]=v[i][j];
            else if(i==n/2) tmp[n-j-1][j]=v[i][j];
            else if(j==n/2) tmp[i][i]=v[i][j];
            else if((i+j)==n-1) tmp[i][n/2]=v[i][j];
            else tmp[i][j]=v[i][j];
        }
    }
    
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n,c;
        cin >> n >> c;
        vector<vector<int>> v;
        
        for(int i=0;i<n;i++) {
            vector<int> vi;
            for(int j=0;j<n;j++) {
                int k;
                cin >>k;
                vi.push_back(k);
            }
            v.push_back(vi);
        }
        
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<n;j++) {
//                cout << v[i][j] << " ";
//            }
//            cout << endl;
//        }
        
        // 시계
        if(c>0) {
//            vector<vector<int>> vv;
            for(int i=0;i<c/45;i++) {
                v=clock1(v);
            }
        }
        // 반시계
        else {
            for(int i=0;i<abs(c)/45;i++) {
                v=clock2(v);
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        
    }
}
