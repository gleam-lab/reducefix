#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Item {
    int a, b;
};

bool cmp(Item x, Item y) {
    return x.a < y.a;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<Item> items(N);
    for (int i = 0; i < N; ++i)
        cin >> items[i].a;
    for (int i = 0; i < N; ++i)
        cin >> items[i].b;

    sort(items.begin(), items.end(), cmp);

    // Min-heap to keep track of the K smallest B values among the top N-K+1 A values
    priority_queue<int> pq;
    ll sum_b = 0;
    ll res = INF;

    // Initialize heap with last K elements' B values and their sum
    for (int i = N - K + 1; i < N; ++i)
        pq.push(-items[i].b), sum_b += items[i].b;

    // Iterate from right to left, maintaining a window of size K
    for (int i = N - K; i >= 0; --i) {
        if (pq.size() >= K) {
            sum_b += pq.top();
            pq.pop();
        }
        pq.push(-items[i].b);
        sum_b += items[i].b;

        if (pq.size() == K)
            res = min(res, items[i].a * sum_b);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}