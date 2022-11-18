//
//  swea 1948.cpp
//  swea
//  memory: 13536 KB
//  time: 6 ms
//  Created by 다곰 on 2022/11/18.
//

#include<iostream>

using namespace std;

int main()
{
    int test_case=1;
    int T;
    
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    cin>>T;

    while (T--) {
        int m1,d1,m2,d2;
        cin >> m1 >> d1 >> m2 >> d2;
        
        int ans=0;
        if (m1==m2) ans=d2-d1+1;
        else if(m2-m1==1) ans=month[d1]-m1+d2+1;
        else {
            ans=month[m1]-d1;
            for (int i=m1+1; i<m2; i++) {
                ans+=month[i];
            }
            ans+=d2+1;
        }
        
        cout << "#" << test_case << " " << ans << endl;
        test_case++;
    }
    
    return 0;
}

//* 날짜 별로 마지막 날짜 배열에 저장하기: int month[13];

//1. 첫째 날짜의 달과 둘째 날짜의 달이 같을 경우: 둘째 일-첫째 일+1
//2. 다를 경우: (첫째 달 마지막 날짜 - 첫째 날)+그 사이 마지막 날짜들+둘째 날짜+1
