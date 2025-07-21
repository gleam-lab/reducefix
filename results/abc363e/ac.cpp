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

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
int h[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}, g[1005][1005];
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int ans = n * m;
	priority_queue<pair<int, PII>> q;
	vector<vector<int>> a(n + 1, vector<int> (m + 1));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if(j == 1 || i == 1 || i == n || j == m)
			g[i][j]++, q.push({-a[i][j], {i, j}});
		}
	}
	for(int i = 1; i <= k; i++)
	{
		while(!q.empty())
		{
			pair<int, PII> now = q.top();
			if(-now.x <= i)
			{
				ans--;
				q.pop();
				for(int j = 0; j < 4; j++)
				{
					int x = now.y.x + h[j][0], y = now.y.y + h[j][1];
					if(x > 0 && y > 0 && x <= n && y <= m && !g[x][y])
					{
						g[x][y]++;
						q.push({-a[x][y], {x, y}});
					}
				}
			}
			else
			break;
		}
		cout << ans << endl;
	}
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