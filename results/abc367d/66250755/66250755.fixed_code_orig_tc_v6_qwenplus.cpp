#include<bits/stdc++.h>
using namespace std;
int n,m,a[400005],w[400005];
long long an;
map<int,int> t;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=m;
		a[i+n]=a[i];
	}
	t[0]++;
	for(int i=1;i<2*n;i++)
	{
		w[i]=(w[i-1]+a[i])%m;
		if(i>=n)
		{
			an+=t[w[i]];
		}
		if(i>=n) t[w[i-n]]--;
		t[w[i]]++;
	}
	cout<<an;
	return 0;
}