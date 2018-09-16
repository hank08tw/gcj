#include <iostream>
using namespace std;
int num[105];
int dp[105][105];
int main(){
	int t,p,q;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> p >> q;
		num[0]=0;
		num[q+1]=p+1;
		for(int j=1;j<=q;j++){
			cin >> num[j];
		}
		for(int j=0;j<=q;j++){
			dp[j][j+1]=0;
		}
		for(int w=2;w<=q+1;w++){
			for(int l=0;l+w<=q+1;l++){
				int r=l+w;
				int tmp=2147483647;
				for(int m=l+1;m<l+w;m++){
					tmp=min(tmp,dp[l][m]+dp[m][r]);
				}
				dp[l][r]=tmp+num[r]-num[l]-2;
			}
		}
		cout << "Case #" << i << ": " << dp[0][q+1] << endl;
	}
}
