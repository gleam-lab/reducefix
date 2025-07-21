#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
const int INF = 1e9 + 7;

vector<ll> arr, brr;
vector<vector<ll>> dis;

void init() {
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= brr.size(); ++i) {
        int x = brr[i - 1];
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = it - arr.begin();
        int dist = min(idx * INF, (int)(arr.size() - idx) * INF);
        dis[i].resize(2);
        dis[i][0] = dist;
        if(it != arr.end()) dis[i][1] = abs(*it - x);
        if(it != arr.begin()) dis[i][2] = abs(*(it - 1) - x);
    }
}

void solve(int k) {
    int ans = INF;
    for(int i = 1; i <= brr.size(); ++i) {
        if(dis[i][1] == k || dis[i][2] == k) ans = min(ans, dis[i][0]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    arr.resize(n), brr.resize(q);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < q; ++i) cin >> brr[i];
    
    dis.resize(q + 1);
    init();
    
    for(int i = 0; i < q; ++i) {
        solve(brr[i]);
    }
    
    return 0;
}