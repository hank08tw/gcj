#include <iostream>
using namespace std;
#define swap(a,b) a=a+b,b=a-b,a=a-b
string a[40];
int line[40];
int main(){
	int t,n;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> a[j];
		}
		for(int j=0;j<n;j++){
			line[j]=-1;
			for(int k=0;k<n;k++){
				if(a[j][k]=='1'){
					line[j]=k;
				}
			}
		}
		int res=0;
		for(int j=0;j<n;j++){
			int pos=-1;
			for(int k=j;k<n;k++){
				if(line[k]<=j){
					pos=k;
					break;
				}
			}
			for(int k=pos;k>j;k--){
				swap(line[k],line[k-1]);
				res++;
			}
		}
		cout << "Case #" << i << ": " << res << endl;
	}
} 
