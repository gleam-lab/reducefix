#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<double, int>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct Node {
    double ratio;
    int index;
};

bool cmp(Node &a, Node &b) {
    return a.ratio > b.ratio;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            cin >> nodes[i].index >> nodes[i].ratio;
        }

        sort(nodes.begin(), nodes.end(), cmp);

        int sum_b = 0;
        double max_a = 0;

        for (int i = 0; i < k; ++i) {
            sum_b += nodes[i].index;
            max_a = max(max_a, nodes[i].ratio);
        }

        int result = static_cast<int>(max_a * sum_b);
        cout << result << endl;
    }

    return 0;
}