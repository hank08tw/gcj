//o(m*2^m)
#include <algorithm>
#include <iostream>
#include <iomanip>
//#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
//#include <cstdlib>
//#include <cctype>
#include <cmath>
//#include <climits>
//#include <numeric>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
const int inf=0x3f3f3f3f;
#define PI acos(-1)


void solve(){
	int m,x;
	double p;
	scanf("%d %lf %d",&m,&p,&x);
	if(x==1000000){printf("1.0000000000\n");return;}
	double dp[16][1 << 15];
	dp[1][0]=0;
	dp[1][1]=p;
	for(int i=2;i<=m;i++){
		for(int j=0;j< (1 << i);j++){
			int k;
			dp[i][j]=0;
			if(j%2){
				k=j/2;
				for(int range=1;k-range+1>=0&&k+range<(1 << (i-1));range++){
                                	dp[i][j]=max(dp[i][j],p*dp[i-1][k+range]+(1-p)*(dp[i-1][k-range+1]));
                        	}
			}
			else{ k=j/2-1;
				for(int range=1;k-range+1>=0&&k+range+1<(1 << (i-1));range++){
                                	dp[i][j]=max(dp[i][j],p*dp[i-1][k+range+1]+(1-p)*(dp[i-1][k-range+1]));
                        	}
			}
			if(j<(1<<(i-1))){
				dp[i][j]=max(dp[i][j],dp[i-1][j]*p);
				
			}else{
				dp[i][j]=max(p+(1-p)*dp[i-1][j-(1<<(i-1))],dp[i][j]);
			}
		}
	}
	double tmp=(double)x/1000000;
	tmp*=(1 << m);
	int n=floor(tmp);
	printf("%.10f\n",dp[m][n]);
}
int main(){
        int T;
        scanf("%d",&T);
        for(int iii=1;iii<=T;iii++){
                printf("Case #%d: ",iii);
                solve();
        }
        return 0;
}
