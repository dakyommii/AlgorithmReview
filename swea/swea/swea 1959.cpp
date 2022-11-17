//
//  swea 1959.cpp
//  swea
//  memory: 13536 KB
//  time: 6 ms
//  Created by 다곰 on 2022/11/17.
//

#include<iostream>

using namespace std;

int main()
{
    int test_case=1;
    int T;

    cin>>T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        
        int ans=-2000;
        int a[20];
        int b[20];
        for (int i=1; i<=n; i++) {
            int k;
            cin >> k;
            a[i]=k;
        }
        
        for (int i=1; i<=m; i++) {
            int k;
            cin >> k;
            b[i]=k;
        }
        
        // a가 더 길 경우
        int mv;
        if(n==m) {
            int cnt=0;
            for (int i=1; i<=n; i++) cnt+=a[i]*b[i];

            ans=cnt;
        }
        else if (n>m) {
            mv=n-m;
            for (int i=0; i<=mv; i++) {
                int cnt=0;
                for (int j=1; j<=m; j++) cnt+=a[j+i]*b[j];

                ans=max(ans, cnt);
            }
            
        }
        // b가 더 길 경우
        else {
            mv=m-n;
            for (int i=0; i<=mv; i++) {
                int cnt=0;
                for (int j=1; j<=n; j++) cnt+=a[j]*b[j+i];

                ans=max(ans, cnt);
            }
        }
        
        cout << "#" << test_case << " " << ans << endl;
        test_case++;
        
    }
    
    return 0;
}

//* int A[20][20];
//* int B[20][20];
//* max 값 계산을 위한 변수: int ans;

//A: N개의 숫자로 구성된 문자열 A[1]~A[N]
//B: M개의 숫자로 구성된 문자열 B[1]~B[M]

//1. A와 B 중에 길이가 더 적은 배열을 움직이면서 더하기
//2. 배열을 움직일 때는 A 길이-B 길이 만큼을 마지노선으로 움직일 수 있음
//3. 한 바퀴 계산하면 max 값 갱신
