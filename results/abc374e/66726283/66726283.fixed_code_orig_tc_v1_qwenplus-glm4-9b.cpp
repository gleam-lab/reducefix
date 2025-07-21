#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

template<typename T>
using Min.PriorityQueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using namespace std;

#define int long long

int n;
int x;
vector<pair<int, pair<int, int>>> a; // {b, {p, q} }

int c[105];
bool check(int mid) {
    for (int i = 0; i <= n; ++i) {
        c[i] = numeric_limits<int>::max();
    }

    Min.PriorityQueue<pair<int, int>> pq; // {cost, index}

    for (int i = 0; i < n; ++i) {
        int b = a[i].first;
        int p = a[i].second.first;
        int q = a[i].second.second;
        
        for (int j = 0; j <= b; ++j) {
            pq.push({j * p + q * (mid - j * a[i].second.first) / a[i].first, i});
        }
    }

    while (!pq.empty()) {
        auto [cost, idx] = pq.top();
        pq.pop();
        c[idx + 1] = min(c[idx + 1], cost);
    }

    int ans = accumulate(c + 1, c + n + 1, 0LL);
    return ans <= x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }

    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l;
    return 0;
}