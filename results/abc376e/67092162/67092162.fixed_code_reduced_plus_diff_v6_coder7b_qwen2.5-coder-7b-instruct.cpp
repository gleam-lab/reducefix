#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
typedef long long ll;

struct Node {
    int a, b;
};

bool cmp(const Node &x, const Node &y) {
    if (x.a != y.a) return x.a > y.a;
    return x.b < y.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Node> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].a >> v[i].b;
        }

        sort(v.begin(), v.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0, ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            pq.push(v[i].b);
            sum += v[i].b;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = min(ans, static_cast<ll>(v[i].a) * sum);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}