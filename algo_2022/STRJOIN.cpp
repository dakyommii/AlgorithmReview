//
//  STRJOIN.cpp
//  algo_2022
//
//  Created by yujeong on 2022/03/06.
//

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    int num[1000];
    
    while (tc--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> num[i];
        }
                
        priority_queue< int, vector<int>, greater<int> > q;
        for (int i=0; i<n; i++) {
            q.push(num[i]);  // 작은거 부터 들어감
        }
        int ret = 0;
        while (q.size() > 1) {
            int min1 = q.top();
            q.pop();
            int min2 = q.top();
            q.pop();
            q.push(min1 + min2);
            ret +=  min1 + min2;
        }
        
        cout << ret << endl;
                
    }
    return 0;
}
