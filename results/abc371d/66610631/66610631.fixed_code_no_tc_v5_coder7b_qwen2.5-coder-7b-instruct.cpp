#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 2e5+7;
int main() {
	int n,q;
	cin >> n;
	vector<ll>pos(n+1),pop(n+1),sum(n+1);
	for(int i=1;i<=n;i++){
		cin >> pos[i];
	}
	for(int i=1;i<=n;i++){
		cin >> pop[i];
		sum[i]=sum[i-1]+pop[i];
	}
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		auto it_l = lower_bound(pos.begin()+1,pos.end(),l)-pos.begin();
		auto it_r = upper_bound(pos.begin()+1,pos.end(),r)-pos.begin();
		cout << sum[it_r-1]-(it_l==1?0:sum[it_l-2]) << endl;
	}
	return 0;
}