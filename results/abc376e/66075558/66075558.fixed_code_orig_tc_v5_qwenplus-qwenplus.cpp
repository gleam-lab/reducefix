#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Item {
    int a, b;
};

bool compare(Item x, Item y) {
    return x.a < y.a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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

        sort(items.begin(), items.end(), compare);

        priority_queue<int> max_heap;
        int sum_b = 0;
        int result = 1e18;

        for (int i = 0; i < N; ++i) {
            if (max_heap.size() >= K - 1) {
                // We have K-1 elements in heap, we can form a group with current item
                int total = sum_b + items[i].b;
                result = min(result, items[i].a * total);
            }

            max_heap.push(items[i].b);
            sum_b += items[i].b;

            if (max_heap.size() >= K) {
                // Maintain only K-1 elements in heap for next iteration
                sum_b -= max_heap.top();
                max_heap.pop();
            }
        }

        cout << result << '\n';
    }

    return 0;
}