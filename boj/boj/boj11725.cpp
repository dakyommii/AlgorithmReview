//
//  boj11725.cpp
//  boj
//  memory: 12488 KB
//  time: 48 ms
//  Created by 다곰 on 2023/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[100001];
int parents[100001]={0};
void par(int c) {
    for(int i=0;i<arr[c].size();i++) {
        int n=arr[c][i];
        if(parents[n]==0) {
            parents[n]=c;
            par(n);
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    parents[1]=1;
    par(1);

    for(int i=2;i<=n;i++) {
        cout << parents[i] << '\n';
    }
}


