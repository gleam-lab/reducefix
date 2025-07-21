#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Queue to store the K smallest and K largest elements
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    
    // Fill the heaps with the first K elements
    for (int i = 0; i < k; i++) {
        min_heap.push(a[i]);
    }
    for (int i = n - k; i < n; i++) {
        max_heap.push(a[i]);
    }

    long long min_range = LLONG_MAX;
    long long max_val, min_val;

    // Calculate the initial minimum range
    max_val = *max_heap.top();
    min_val = *min_heap.top();
    min_range = max_val - min_val;

    // Now iterate over the elements between K and N-K-1
    for (int i = k; i < n - k; i++) {
        // Remove the smallest element from the min_heap
        min_heap.pop();
        // Add the new element to the min_heap
        min_heap.push(a[i]);
        // Remove the largest element from the max_heap
        max_heap.pop();
        // Add the new element to the max_heap
        max_heap.push(a[i]);

        // Calculate the new range
        max_val = *max_heap.top();
        min_val = *min_heap.top();
        min_range = min(min_range, max_val - min_val);
    }

    // Output the minimum possible range
    cout << min_range << endl;
    return 0;
}