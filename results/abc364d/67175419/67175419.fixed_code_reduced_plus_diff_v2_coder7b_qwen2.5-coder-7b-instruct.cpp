#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, m, k;
ll a[N], b[N];

struct Node {
    ll val;
    int idx;
};

bool cmp(Node &a, Node &b) {
    return a.val < b.val;
}

vector<ll> solve(vector<Node> v, int k) {
    sort(v.begin(), v.end(), cmp);
    vector<ll> ans;
    for (int i = k - 1; i < v.size(); ++i) {
        ans.push_back(v[i].val);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i] >> k[i];
    }

    vector<ll> res(m);
    for (int i = 1; i <= m; ++i) {
        vector<Node> v(n);
        for (int j = 1; j <= n; ++j) {
            v[j - 1].val = abs(b[i] - a[j]);
            v[j - 1].idx = j;
        }
        auto ans = solve(v, k[i]);
        res[i - 1] = ans[0];
    }

    for (int i = 0; i < m; ++i) {
        cout << res[i] << '\n';
    }

    return 0;
}