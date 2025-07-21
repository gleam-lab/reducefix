#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Define a structure to hold pairs (A_i, B_i)
struct Item {
    int a;
    int b;
};

// Comparator for sorting by A
bool compareItem(const Item& x, const Item& y) {
    return x.a < y.a;
}

int main() {
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

        // Sort items based on A in ascending order
        sort(items.begin(), items.end(), compareItem);

        // Use a min-heap to keep track of smallest K-1 values of B
        priority_queue<int, vector<int>, greater<>> pq;
        long long sum_b = 0;
        long long result = 1LL << 60; // Set to large number initially

        // First K-1 items' B values go into the heap
        for (int i = 0; i < K - 1; ++i) {
            sum_b += items[i].b;
            pq.push(items[i].b);
        }

        // Now iterate over the rest as possible max A
        for (int i = K - 1; i < N; ++i) {
            long long current_score = 1LL * items[i].a * (sum_b + items[i].b);
            result = min(result, current_score);

            // Maintain the heap: add current item's B if it's smaller than the largest in the heap
            if (K > 1 && items[i].b < pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].b);
                sum_b += items[i].b;
            }
        }

        cout << result << "\n";
    }

    return 0;
}