#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Use a min-heap to store the largest K elements
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Push all elements into the heap
    for (int i = 0; i < n; i++) {
        min_heap.push(A[i]);
    }

    // We need to remove K elements, so we pop K elements from the heap
    for (int i = 0; i < k; i++) {
        min_heap.pop();
    }

    // The size of the remaining elements is n - k
    vector<int> remaining(n - k);

    // Fill the remaining vector with the elements that are not removed
    for (int i = 0; i < n - k; i++) {
        remaining[i] = min_heap.top();
        min_heap.pop();
    }

    // The minimum and maximum of the remaining elements are the bounds of sequence B
    int min_val = *min_element(remaining.begin(), remaining.end());
    int max_val = *max_element(remaining.begin(), remaining.end());

    // The minimum possible value is the difference between the maximum and minimum of B
    cout << max_val - min_val << endl;

    return 0;
}