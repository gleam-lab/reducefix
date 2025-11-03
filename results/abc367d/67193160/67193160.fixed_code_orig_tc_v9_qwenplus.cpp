#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int i,j,x,y,z,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	long long ans = 0;
	vector<int> prefix(n+1, 0);
	unordered_map<int, int> count;
	count[0] = 1;
	
	for(i=1;i<=n;i++) {
		prefix[i] = (prefix[i-1] + a[i]) % m;
		ans += count[prefix[i]];
		count[prefix[i]]++;
	}
	
	cout<<ans;
	return 0;
}