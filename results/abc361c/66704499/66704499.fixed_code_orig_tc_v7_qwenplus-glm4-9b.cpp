#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0, r = n - k - 1;
    priority_queue<int, vector<int>, greater<int>> max_heap;
    priority_queue<int> min_heap;

    double min_range = INT_MAX;

    while (l <= r) {
        min_heap.push(a[l]);
        max_heap.push(-a[r]);
        l++;
        r--;

        while (!max_heap.empty() && -max_heap.top() < a[l]) {
            max_heap.pop();
        }

        while (!min_heap.empty() && min_heap.top() < a[r]) {
            min_heap.pop();
        }

        int max_val = -max_heap.top();
        int min_val = min_heap.top();
        min_range = min(min_range, max_val - min_val);
    }

    cout << min_range << endl;

    return 0;
}