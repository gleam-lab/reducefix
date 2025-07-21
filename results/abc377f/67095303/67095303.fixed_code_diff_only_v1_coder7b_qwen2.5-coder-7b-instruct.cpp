#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

int qpowm(int a, int b, int m) {
	int r = 1;
	while (b) {
		if (b & 1)(r *= a) %= m;
		(a *= a) %= m, b >>= 1;
	}
	return r;
}

int qpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r *= a;
		a *= a;
		b >>= 1;
	}
	return r;
}


void solve() {
	int n, q;
	cin >> n >> q;
	vector<PII>pieces(q);
	for(int i=0;i<q;++i){
	    cin>>pieces[i].first>>pieces[i].second;
	}

	bool board[n+1][n+1]={false};
	for(auto p:pieces){
	    board[p.first][p.second]=true;
	}

	int ans=0;
	for(int i=1;i<=n;++i){
	    for(int j=1;j<=n;++j){
	        if(!board[i][j]){
	            bool flag=true;
	            for(auto p:pieces){
	                if(i==p.first||j==p.second||i+p.first==j+p.second||i-p.first==j-p.second){
	                    flag=false;
	                    break;
	                }
	            }
	            if(flag)ans++;
	        }
	    }
	}

	cout << ans << endl;
}

signed main() {

	int _ = 1;
//	cin>>_;
	while (_--) {
		solve();
	}

	return 0;
}