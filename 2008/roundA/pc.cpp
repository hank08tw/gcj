#include <iostream>
#include <iomanip>
using namespace std;
struct mat{
	int a1,a2,a3,a4;
	mat(int a=1,int b=0,int c=0,int d=1){
		a1=a;a2=b;a3=c;a4=d;	
	}
};
mat ii;
mat f(3,5,1,3);
mat tmp;
void solve(long long n){
	if(n==0)return;
	if(n==1){tmp.a1=f.a1;tmp.a2=f.a2;tmp.a3=f.a3;tmp.a4=f.a4;return;}
	solve(n/2);
	mat newtmp;
	newtmp.a1=tmp.a1*tmp.a1%1000+tmp.a2*tmp.a3%1000;
	newtmp.a2=tmp.a1*tmp.a2%1000+tmp.a2*tmp.a4%1000;
	newtmp.a3=tmp.a1*tmp.a3%1000+tmp.a3*tmp.a4%1000;
	newtmp.a4=tmp.a2*tmp.a3%1000+tmp.a4*tmp.a4%1000;
	tmp.a1=newtmp.a1;
	tmp.a2=newtmp.a2;
	tmp.a3=newtmp.a3;
	tmp.a4=newtmp.a4;
	if(n%2==1){
		mat newtmp2;
        	newtmp2.a1=tmp.a1*f.a1%1000+tmp.a2*f.a3%1000;
        	newtmp2.a2=tmp.a1*f.a2%1000+tmp.a2*f.a4%1000;
        	newtmp2.a3=tmp.a3*f.a1%1000+tmp.a4*f.a3%1000;
        	newtmp2.a4=tmp.a3*f.a2%1000+tmp.a4*f.a4%1000;
        	tmp.a1=newtmp2.a1;
        	tmp.a2=newtmp2.a2;
        	tmp.a3=newtmp2.a3;
        	tmp.a4=newtmp2.a4;
	}
}
int main(){
	long long t,n;
	cin >> t;
	for(int i=1;i<=t;i++){
		tmp.a1=1;
		tmp.a2=0;
		tmp.a3=0;
		tmp.a4=1;
		cin >> n;
		solve(n);
		int ans=(2*tmp.a1)%1000-1;
		//cout << "Case #" << i << ": " << fixed << setprecision(3) << ans << endl;
		printf("Case #%d: %03d\n",i,ans);
	}	
}
