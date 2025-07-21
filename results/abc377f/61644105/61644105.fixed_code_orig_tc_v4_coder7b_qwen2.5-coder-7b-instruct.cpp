#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e9 + 5;

ll n, m, cnt[4];

struct point {
    ll x, y;
};

bool cmp(const point& a, const point& b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    vector<point> ps(m);
    for(int i = 0; i < m; ++i) {
        cin >> ps[i].x >> ps[i].y;
        ++cnt[(ps[i].x + ps[i].y) & 1];
        ++cnt[(ps[i].x - ps[i].y + 1) & 1];
        ++cnt[ps[i].x & 1];
        ++cnt[ps[i].y & 1];
    }

    sort(ps.begin(), ps.end(), cmp);

    ll ans = n * n;
    for(int i = 0; i < m; ++i) {
        --ans;
        ans -= (ps[i].x == 1 ? cnt[1] : cnt[0]);
        ans -= (ps[i].y == 1 ? cnt[3] : cnt[2]);
        --cnt[(ps[i].x + ps[i].y) & 1];
        --cnt[(ps[i].x - ps[i].y + 1) & 1];
        --cnt[ps[i].x & 1];
        --cnt[ps[i].y & 1];
    }

    cout << ans << endl;
    return 0;
}