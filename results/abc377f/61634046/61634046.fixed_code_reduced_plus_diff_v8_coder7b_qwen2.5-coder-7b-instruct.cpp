#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MX = 1e9 + 5;

int n, m, cnt[MX], vis[MX], ans;

struct P {
    int x, y;
};

vector<P> ps;

bool cmp(P a, P b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        ps.push_back({x, y});
    }
    sort(ps.begin(), ps.end());
    for(auto [x, y] : ps) {
        while(cnt[x]) --cnt[x];
        while(cnt[y]) --cnt[y];
        while(cnt[x + y]) --cnt[x + y];
        while(cnt[x - y + MX]) --cnt[x - y + MX];
        ++cnt[x];
        ++cnt[y];
        ++cnt[x + y];
        ++cnt[x - y + MX];
        ++ans;
    }
    cout << n * n - ans << endl;
    return 0;
}