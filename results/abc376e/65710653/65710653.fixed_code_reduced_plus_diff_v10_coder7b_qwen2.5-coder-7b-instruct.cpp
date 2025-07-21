#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll INF = 1e18;

struct Compare {
    bool operator()(const pii &a, const pii &b) const {
        return a.second > b.second || (a.second == b.second && a.first > b.first);
    }
};

vector<ll> solve(int n, int k, vector<ll> a, vector<ll> b) {
    priority_queue<pii, vector<pii>, Compare> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({a[i], b[i]});
    }

    vector<ll> res(k);
    for (int i = 0; i < k; ++i) {
        auto [x, y] = pq.top(); pq.pop();
        res[i] = x * y;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        auto res = solve(n, k, a, b);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}