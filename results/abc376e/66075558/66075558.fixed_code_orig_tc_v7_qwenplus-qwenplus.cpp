#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Item {
    int a, b;
};

bool compare(Item x, Item y) {
    return x.a < y.a;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<Item> items(N);
        for (int i = 0; i < N; ++i)
            cin >> items[i].a;
        for (int i = 0; i < N; ++i)
            cin >> items[i].b;
        
        // Sort by A values
        sort(items.begin(), items.end(), compare);
        
        ll sum_b = 0;
        priority_queue<int> min_heap;  // to maintain top K smallest B values
        ll res = 1e18;

        // We'll use a max-heap later to remove largest elements when needed
        priority_queue<int, vector<int>, greater<int>> max_heap;

        // First, select first K-1 elements' B values and keep them in a buffer
        vector<ll> prefix_min_b_sums(N);
        priority_queue<int> pq;
        ll sum = 0;

        for (int i = 0; i < N; ++i) {
            if (i < K - 1) {
                pq.push(items[i].b);
                sum += items[i].b;
                prefix_min_b_sums[i] = sum;
            } else {
                pq.push(items[i].b);
                sum += items[i].b;
                // Remove the largest among the K kept
                int removed = pq.top();
                pq.pop();
                sum -= removed;
                prefix_min_b_sums[i] = sum;
            }
        }

        // Now iterate from K-1 to N-1 and compute final answer
        priority_queue<int> heap;
        ll total_b = 0;
        for (int i = 0; i < K; ++i) {
            heap.push(items[i].b);
            total_b += items[i].b;
        }

        res = min(res, (ll)items[K - 1].a * total_b);

        for (int i = K; i < N; ++i) {
            // Add current item's B to heap
            if (items[i].b < heap.top()) {
                total_b -= heap.top();
                heap.pop();
                heap.push(items[i].b);
                total_b += items[i].b;
            }
            res = min(res, (ll)items[i].a * total_b);
        }

        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}