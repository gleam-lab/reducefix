#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int INF = 2e9;

struct Node {
    int val;
    int idx;
};

bool cmp(Node a, Node b) {
    return a.val > b.val || (a.val == b.val && a.idx < b.idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Node> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].val;
            a[i].idx = i;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end(), cmp);

        priority_queue<int> pq;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            pq.push(b[a[i].idx]);
            sum += b[a[i].idx];
        }

        long long res = sum * a[k - 1].val;
        for (int i = k; i < n; ++i) {
            sum += b[a[i].idx] - pq.top();
            pq.pop();
            pq.push(b[a[i].idx]);
            res = min(res, sum * a[i].val);
        }

        cout << res << "\n";
    }

    return 0;
}