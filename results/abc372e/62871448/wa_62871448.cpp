#include<bits/stdc++.h>
using namespace std;
int as[200005][60];
int fa[200005];
int n,q;
int ch[11];
int gtf(int x)
{
	if(x==fa[x])return x;
	return fa[x]=gtf(fa[x]);
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
		
		memset(as[i],-1,sizeof(as[i]));
		as[i][0]=i;
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
				int lh=0,rh=0;
				while(lh+rh<10)
				{
					if(as[gtf(ix)][lh]>as[gtf(iy)][rh])
					{
						ch[lh+rh]=as[gtf(ix)][lh];
						lh++;
					}
					else
					{
						ch[lh+rh]=as[gtf(iy)][rh];
						rh++;
					}
				}
				for(int j=0;j<10;j++)as[gtf(ix)][j]=ch[j];
				fa[gtf(iy)]=gtf(ix);
			}
		}
		else
		{
			//for(int j=0;j<10;j++)cout<<as[gtf(ix)][j]<<";";
			//cout<<"\n";
			cout<<as[gtf(ix)][iy-1]<<"\n";
		}
		/*
		for(int j=1;j<=n;j++)
		{
			if(fa[j]==j)
			{
				cout<<j<<":";
				for(int k=0;k<10;k++)
				{
					cout<<as[j][k]<<" ";
				}
				cout<<"\n";
			}
		}
		*/
		//for(int j=1;j<=n;j++)cout<<fa[j]<<",";
		//cout<<"\n";
	}
	//while(1);
	return 0;
}
