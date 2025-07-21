#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
//~FZY.//
#include<bits/stdc++.h>
#define Heap_int priority_queue<int, vector<int>, greater<int>>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define out(x) cout << ((x) ? "YES" : "NO") << endl
#define mod(x, P) (((x) % (P) + (P)) % (P))
//#define mod(x) (((x) % (P) + (P)) % (P))
#define ULL unsigned long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define lowbit(x) ((x) & -(x))
#define LL long long
#define pb push_back
#define gcd __gcd
#define Big __int128
#define endl "\n"
#define x first
#define y second
//#define int LL
using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
int g[N];
void solve(){
	int n, m;
	cin >> n >> m;
	LL ans = 0, sum = 0, cnt = 0;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i < n - 1)
		sum = (sum + a[i]) % m, g[sum]++;
	}
	for(int i = 0; i < n; i++)
	{
		ans += g[cnt];
		cnt = (cnt + a[i]) % m;
		g[cnt]--;
		sum = (sum + a[(i - 1 + n) % n]) % m;
		g[sum]++;
	}
	cout << ans;
}
signed main(){
	IOS;

	int T = 1;
	//cin >> T;
	while(T--){
		solve();
	}
	return 0;
}