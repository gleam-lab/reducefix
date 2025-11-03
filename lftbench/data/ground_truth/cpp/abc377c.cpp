#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
ll n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	set<pair<int, int>>s;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		auto it = make_pair(x, y);
		s.insert(it);
		for (int j = 0; j < 8; j++)
		{
			int nx = x + dx[j], ny = y + dy[j];
			if (nx<1 || nx>n || ny<1 || ny>n)continue;
			auto it = make_pair(nx, ny);
			s.insert(it);
		}
	}
	ll len = s.size();
	cout << n * n - len << endl;
	return 0;
}