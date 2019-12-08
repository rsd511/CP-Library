#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c,d,p,q,y,i;
		cin>>n>>a>>b>>c>>d>>p>>q>>y;

		int x[n+1];
		for(i=1;i<=n;i++)
			cin>>x[i];

		int walk=abs(x[b]-x[a])*p;

		if(abs(x[c]-x[a])*p>y)
			cout<<walk<<'\n';
		else{
			int train=y+abs(x[d]-x[c])*q+abs(x[b]-x[d])*p;
			int ans=min(walk,train);
			cout<<ans<<'\n';
		}
	}
}
