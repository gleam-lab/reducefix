#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int big = 1e9 + 7;

struct Node {
    int idx, dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];

    vl ans(q);
    rep(j, q) {
        int b, k;
        cin >> b >> k;
        priority_queue<Node> pq;
        rep(i, n) {
            int d = abs(a[i] - b);
            pq.push({i, d});
            if (pq.size() > k) pq.pop();
        }
        ans[j] = pq.top().dist;
    }

    rep(j, q) cout << ans[j] << '\n';

    return 0;
}