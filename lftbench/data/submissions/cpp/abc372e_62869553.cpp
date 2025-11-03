#include<bits/stdc++.h>
using namespace std;
int as[200005][21];
int fa[200005];
int n,q;
int gtf(int x)
{
	int ret;
	ret=x;
	while(fa[ret]!=ret)ret=fa[ret];
	int l,t;
	t=x;
	while(fa[t]!=t)
	{
		l=t;
		t=fa[t];
		fa[l]=ret;
	}
	return ret;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>q>>n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		as[i][0]=i;
		for(int j=1;j<10;j++)as[i][j]=-1;
	}
	int op,ix,iy;
	for(int i=0;i<n;i++)
	{
		cin>>op>>ix>>iy;
		//printf("%d %d %d\n",op,ix,iy);
		if(op==1)
		{
			if(gtf(ix)!=gtf(iy))
			{
				for(int i=0;i<10;i++)as[gtf(ix)][i+10]=as[gtf(iy)][i];
				sort(as[gtf(ix)],as[gtf(ix)]+20,cmp);
				fa[gtf(iy)]=gtf(ix);
			}
			
		}
		else
		{
			//for(int j=0;j<10;j++)cout<<as[gtf(ix)][j]<<";";
			//cout<<"\n";
			cout<<as[gtf(ix)][iy-1]<<"\n";
		}
		//for(int j=1;j<=n;j++)cout<<fa[j]<<",";
		//cout<<"\n";
	}
	//while(1);
	return 0;
}
