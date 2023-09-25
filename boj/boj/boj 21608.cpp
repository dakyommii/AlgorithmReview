//  boj 21608.cpp
//  boj
//
//  Created by 다곰 on 2022/11/04.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;
bool love[401][401]={false};
int board[21][21]={0,};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct node {
    int x;
    int y;
    int lk;
    int emp;
};

struct cmp {
    
    bool operator()(node& n1, node& n2) {
        if(n1.lk==n2.lk) {
            if(n1.emp==n2.emp) {
                if(n1.x==n2.x) return n1.y>n2.y;
                return n1.x>n2.x;
            }
                
            return n1.emp<n2.emp;
        }
        return n1.lk<n2.lk;
    }
    
};

void sit(int cur) {
    priority_queue<node,vector<node>,cmp> pq;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            
            if(board[i][j]!=0) continue;
            
            int cnt_like=0, cnt_emp=0;
            for(int k=0;k<4;k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];
                
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                
                int next=board[nx][ny];
                
                if(board[nx][ny]==0) cnt_emp++;
                else if(love[cur][next]) cnt_like++;
            }
            
            pq.push({i,j,cnt_like,cnt_emp});
            
        }
    }

    node nd=pq.top();
    board[nd.x][nd.y]=cur;
    
}

int main() {
    
    cin >> n;

    vector<int> seq;
    for(int i=0;i<n*n;i++) {
        int st;
        cin >> st;
        seq.push_back(st);
        
        for(int j=0;j<4;j++) {
            int lk;
            cin >> lk;
            love[st][lk]=true;
        }
    }
    
    for(int i=0;i<seq.size();i++) {
        int cur=seq[i];
        
        sit(cur);
    }
    
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            
            int cur=board[i][j];
            cout<<cur << " ";
            if(cur==0) continue;
            int cnt=0;
            for(int k=0;k<4;k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];
                
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                int next=board[nx][ny];
                
                if(love[cur][next]) cnt++;
            }
            
            ans+=pow(10,cnt-1);
        }
        cout << endl;
    }
    
    cout << ans;
    

}
