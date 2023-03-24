//
//  boj2407.cpp
//  boj
//  memory: 2344 KB
//  time: 0 ms
//  Created by 다곰 on 2023/03/24.
//

#include <iostream>
#include <string>
using namespace std;

string comb[101][101];

string calc(string a, string b) {
    int up=0;
    for(int i=1;i<=a.size();i++) {
        if (i>b.size()) {
            if(up==0) break;
            else if(a[a.size()-i]<'9') {
                a[a.size()-i]+=1;
                up=0;
            }
            else {
                a[a.size()-i]='0';
                if(i==a.size()) return "1"+a;
            }

            continue;
        }
        
        int k = a[a.size()-i]-'0'+b[b.size()-i]-'0'+up;
        up=0;
        if(k<10) a[a.size()-i]=k+'0';
        else {
            up=1;
            a[a.size()-i]=(k%10)+'0';
            if(i==a.size()) return "1"+a;

        }
        
    }
    return a;
}

int main() {
    
    comb[5][0]=comb[5][5]="1";
    comb[5][1]=comb[5][4]="5";
    comb[5][2]=comb[5][3]="10";

    for(int i=6;i<=100;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0 || j==i) comb[i][j]="1";
            else {
                string a=comb[i-1][j-1];
                string b=comb[i-1][j];

                if (a.size()>=b.size()) comb[i][j]=calc(a, b);
                else comb[i][j]=calc(b, a);

            }
        }
    }
    
    int n,m;
    cin >> n >> m;
    cout << comb[n][m];
    
    
}
