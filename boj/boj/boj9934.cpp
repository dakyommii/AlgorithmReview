//
//  boj9934.cpp
//  boj
//  memory: 2208 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/28.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<int> num;

void sol(int l, int r, int depth) {
    int mid=(l+r)/2;
    tree[depth].push_back(num[mid]);
    
    if(r-l ==2) {
        tree[depth+1].push_back(num[l]);
        tree[depth+1].push_back(num[r]);
        return;
    }
    
    // left
    sol(l,mid-1,depth+1);
    
    //right
    sol(mid+1,r,depth+1);
    
}

int main() {
    int k;
    cin >> k;
    tree.resize(k);
    // vector<int> num;
    for(int i=1;i<pow(2,k);i++) {
        int node;
        cin >> node;
        num.push_back(node);
    }

    sol(0,num.size()-1,0);

    for(int i=0;i<tree.size();i++) {
        for(int j=0;j<tree[i].size();j++) {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }
}
