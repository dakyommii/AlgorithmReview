////
////  boj 1275.cpp
////  boj
////
////  Created by 다곰 on 2023/01/10.
////
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define PIV (1<<3)
//long long tree[PIV*2];
//
///*
//void update(long long a, long long b) {
//    
//}
//*/
//
//long long sum(long long x, long long y) {
//    long long ret=0;
//    
//    while(x<=y) {
//        if(x%2==1) ret+=tree[x++];
//        if(y%2==0) ret+=tree[y--];
//        x/=2;
//        y/=2;
//    }
//    
//    return ret;
//}
//
//int main() {
//    long long n,q,x,y,a,b;
//    
//    cin >> n >> q;
//
//    for(int i=1;i<=n;i++) {
//        cin >> tree[i];
//    }
//    
//    for(int i=0;i<q;i++) {
//        cin >> x >> y >> a >> b;
//        
//        cout << sum(x,y) << endl;
//        //update(a,b);
//        tree[a]=b;
//        
//    }
//}
//
///*
//while(l<=r) {
//        if(l%2==1) sum+=idx[l++];
//        if(r%2==0) sum+=idx[r--];
//        l/=2;
//        r/=2;
//    }
//*/
//
////n: 수의 개수
////q: 턴의 개수
////x~y 까지의 합 구하기
////a번째 수를 b로 바꾸기
