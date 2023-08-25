//
//  boj2142.cpp
//  boj
//  memory: 5580 KB
//  time: 1200 ms
//  Created by 다곰 on 2023/08/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

struct node {
    int x;
    int y;
    int cnt;
};

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second<p2.second;
}

int main() {
    int n,t,ans=-1;
    cin >> n >> t;
    vector<pair<int,int>> hole;
    map<pair<int,int>,bool> visit;
    queue<node> q;
    
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x>> y;
        hole.push_back({x,y});
        visit[{x,y}]=false;
    }
    
    sort(hole.begin(), hole.end(), cmp);
    
    q.push({0,0,0});

    while(!q.empty()) {
        int sx=q.front().x;
        int sy=q.front().y;
        int cnt=q.front().cnt;

        q.pop();

        if(sy==t) {
            ans=cnt;
            break;
        }

        if(visit[{sx,sy}]) continue;

        visit[{sx,sy}]=true;

        auto it = lower_bound(hole.begin(), hole.end(), pair<int,int>(0,sy-2), cmp)-hole.begin();
        for(int i=it;i<hole.size()&&abs(hole[i].second-sy)<=2;i++) {

            int nx=hole[i].first;
            int ny=hole[i].second;
     
            if(!visit[{nx,ny}] && abs(nx-sx)<=2 ) {
                q.push({nx,ny,cnt+1});

            }
        }

    }
    
   cout << ans << endl;
    
    

}

