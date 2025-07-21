#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Pair of A_i and B_i
struct Item {
    int a, b;
};

// Sort items by A_i in ascending order
bool compare(Item x, Item y) {
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

    // Sort items based on A_i
    sort(items.begin(), items.end(), compare);

    ll sum_b = 0;
    priority_queue<int> max_heap; // to keep track of the smallest K B's among larger A's
    ll res = numeric_limits<ll>::max();

    // Min-heap to maintain top K smallest B values
    priority_queue<int, vector<int>, greater<>> min_heap;

    // Initialize with the last K elements
    for (int i = N - 1; i >= 0; --i) {
        if ((int)min_heap.size() >= K) {
            // Remove the largest B from the heap to keep only K smallest Bs
            min_heap.pop();
        }
        min_heap.push(items[i].b);
        if (min_heap.size() == K) {
            res = min(res, (ll)items[i].a * accumulate(min_heap, 0LL));
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}