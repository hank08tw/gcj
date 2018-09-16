#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string.h>
using namespace std;
int num1[1000];
int num2[1000];
int main(){
	int t,n;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> num1[j];
		}
		for(int j=0;j<n;j++)cin >> num2[j];
		sort(num1,num1+n);
		//for(int j=0;j<n;j++)cout << num1[j] << " ";	
		sort(num2,num2+n);
		//for(int j=0;j<n;j++)cout << num2[j] << " ";
		long long ans=0;
		for(int j=0;j<n;j++){
			ans+=(long long)num1[j]*(long long)num2[n-j-1];
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
}
