//
//  boj15663.cpp
//  boj
//  memory: 5540 KB
//  time: 860 ms
//  Created by 다곰 on 2023/10/20.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
vector<int> x;
set<vector<int>> s;
int visit[10];

void dfs(int depth) {
    if(x.size()==depth) {
        s.insert(x);
        return;
    }

    for(int i=0;i<v.size();i++) {
        if(!visit[i]) {
            visit[i]=true;
            x.push_back(v[i]);
            dfs(depth);
            visit[i]=false;
            x.pop_back();
        }
    }
}

int main() {
    int n,m;
    cin >> n>>m;
    
    for(int i=0;i<n;i++) {
        int k;
        cin >>k;
        v.push_back(k);
    }
    
    sort(v.begin(), v.end());
    
    dfs(m);
    
    vector<vector<int>> vv(s.begin(),s.end());
    
    for(int i=0;i<vv.size();i++) {
        for(int j=0;j<vv[0].size();j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
 
}

