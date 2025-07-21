#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> rules(n);
    long long x;

    for (int i = 0; i < n; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        rules.push_back({p, a});
        rules.push_back({q, b});
    }
    cin >> x;

    sort(rules.begin(), rules.end());

    long long max_cost = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        long long p = rules[i].first;
        long long a = rules[i].second;
        long long cost = p * a;
        max_cost = max(max_cost, cost);
    }

    cout << max_cost << endl;

    return 0;
}