#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Create a max-heap to store the smallest k elements
    priority_queue<int> max_heap;
    // Create a min-heap to store the largest k elements
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Push the first k elements into the max-heap
    for (int i = 0; i < k; ++i) {
        max_heap.push(a[i]);
    }

    // Push the first k elements into the min-heap
    for (int i = 0; i < k; ++i) {
        min_heap.push(a[i]);
    }

    int min_diff = INT_MAX;
    // Iterate over the rest of the elements
    for (int i = k; i < n; ++i) {
        // Remove the smallest element from the max-heap and add the current element
        max_heap.push(a[i]);
        // Pop the largest element from the min-heap
        min_heap.push(max_heap.top());
        max_heap.pop();

        // Remove the largest element from the min-heap
        min_heap.pop();
        // Add the current element to the min-heap
        min_heap.push(a[i]);

        // Calculate the difference
        int current_diff = max_heap.top() - min_heap.top();
        // Update the minimum difference
        min_diff = min(min_diff, current_diff);
    }

    // The minimum possible value of the maximum value of B minus the minimum value of B
    cout << min_diff << endl;

    return 0;
}