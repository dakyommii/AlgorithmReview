//
//  boj2470.cpp
//  boj
//  memory: 2680 KB
//  time: 16 ms
//  Created by 다곰 on 2023/04/13.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long arr[100001];
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int l=0;
    int r=n-1;
    long long ans;  // 현재 혼합용액 값
    long long mxl=arr[l],mxr=arr[r];    // 시작 음수용액(첫번째 용액), 시작 양수용액(마지막 용액)
    long long res=mxl+mxr;  // 최소혼합용액

    // 굳이 l 이 음수이고 r 이 양수임을 고정하지 않아도 둘 다 양수거나 둘 다 양수이면 어차피 0과 멀어지므로 l<r 조건만 주어도 ㄱㅊ
    while(l<r) {
        ans=arr[l]+arr[r];  // 현재 혼합용액 갱신
        if(abs(res)>abs(ans)) { // 최소혼합용액보다 현재 혼합용액이 0에 가까우면 갱신
            res=ans;
            mxl=arr[l];
            mxr=arr[r];
        }

        if(ans>0) r--;
        else l++;

    }

    cout << mxl << " " << mxr;
}

/*
 2차 풀이: Two Pointer
 memory: 2680 KB
 time: 16 ms
 
 
 #include <iostream>
 #include <vector>
 #include <cstdlib>
 #include <algorithm>
 using namespace std;
 
 int main() {
 int n;
 cin >> n;
 vector<int> v(n);
 for(int i=0;i<n;i++) {
 cin >> v[i];
 }
 sort(v.begin(),v.end());
 
 int st=0,end=n-1;
 long long ans=2000000001;
 long long l1=0,l2=0;
 while(st<end) {
 long long cnt=v[st]+v[end];
 //        cout << cnt << endl;
 
 if(abs(cnt)<abs(ans)) {
 l1=v[st];
 l2=v[end];
 ans=abs(cnt);
 }
 
 if(cnt==0) break;
 if(abs(v[st])>=abs(v[end])) st++;
 else end--;
 }
 
 cout << l1 << " " << l2 << endl;
 }
 */
