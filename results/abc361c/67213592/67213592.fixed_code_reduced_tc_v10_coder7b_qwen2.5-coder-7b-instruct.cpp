#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &val : v) {
        cin >> val;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push(v[i]);
        maxHeap.push(v[i]);
    }

    for (int i = 0; i < k; ++i) {
        minHeap.pop();
        maxHeap.pop();
    }

    int result = maxHeap.top() - minHeap.top();

    cout << result << endl;

    return 0;
}