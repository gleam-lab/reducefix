#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Element {
    int a, b;
};

bool compare(const Element &x, const Element &y) {
    return x.a < y.a;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<Element> elements(N);
        for (int i = 0; i < N; ++i)
            cin >> elements[i].a;

        for (int i = 0; i < N; ++i)
            cin >> elements[i].b;

        sort(elements.begin(), elements.end(), compare);

        priority_queue<int> max_heap;
        int sum_b = 0;
        int result = 1e18;

        // We process the first K-1 smallest A's and accumulate their B's
        for (int i = 0; i < K - 1; ++i) {
            sum_b += elements[i].b;
            max_heap.push(elements[i].b);
        }

        // Now we try all candidates for max A in S: elements[i] will be the max A in subset S
        for (int i = K - 1; i < N; ++i) {
            sum_b += elements[i].b;
            max_heap.push(elements[i].b);

            // Maintain only top K largest B values among first i+1 items
            if (max_heap.size() > K) {
                sum_b -= max_heap.top();
                max_heap.pop();
            }

            result = min(result, elements[i].a * sum_b);
        }

        cout << result << "\n";
    }

    return 0;
}