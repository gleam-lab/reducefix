#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Item {
    int a, b;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<Item> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].a;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].b;
        }

        // Sort items by A value ascending
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Min-heap to keep track of top K B values
        priority_queue<int, vector<int>, greater<>> min_heap;
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        // First select last K elements based on largest A values
        // Then we will move leftward, replacing one element at a time from the right
        for (int i = N - 1; i >= 0; --i) {
            min_heap.push(items[i].b);
            sum_b += items[i].b;

            if (min_heap.size() > K) {
                sum_b -= min_heap.top();
                min_heap.pop();
            }

            if (min_heap.size() == K) {
                res = min(res, items[i].a * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}