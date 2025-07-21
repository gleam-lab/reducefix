#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
long long a[MAXN], b[MAXN];

struct Element {
    long long first, second;
};

bool cmp(const Element& a, const Element& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Element> pairs(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        pairs[i] = {a[i], b[i]};
    }

    sort(pairs.begin(), pairs.end(), cmp);

    priority_queue<long long> pq;
    long long sum = 0, result = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        pq.push(-pairs[i].second); // Store negative to use min-heap as max-heap
        sum += pairs[i].second;

        if (pq.size() > k) {
            sum -= -pq.top(); // Remove the largest element added
            pq.pop();
        }

        if (pq.size() == k) {
            result = min(result, pairs[i].first * sum);
        }
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}