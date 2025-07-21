#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100000 + 5;
long long a[MAXN], b[MAXN];

struct Item {
    int idx, val;
    bool operator<(const Item& other) const { return val > other.val; } // Max heap based on value
};

vector<long long> topKSum(int n, int k, vector<Item>& items) {
    sort(items.begin(), items.end());
    priority_queue<long long> pq;
    long long totalSum = 0;
    for (int i = 0; i < k; ++i) {
        totalSum += items[i].val;
        pq.push(-items[i].val); // Insert negative because we want a min-heap acting as a max-heap
    }
    vector<long long> result(k);
    result[0] = totalSum;
    for (int i = k; i < n; ++i) {
        totalSum += items[i].val - (-pq.top()); // Replace the smallest element with the new one
        pq.pop();
        pq.push(-items[i].val);
        result[i - k + 1] = totalSum;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<Item> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            items[i].idx = i;
            items[i].val = a[i];
        }
        auto sums = topKSum(n, k, items);
        for (int i = 0; i < n - k + 1; ++i) {
            long long ans = sums[i] * b[items[i].idx];
            cout << ans << '\n';
        }
    }

    return 0;
}