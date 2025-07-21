#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Priority queues to maintain the smallest K elements from the left and right ends
    priority_queue<int, vector<int>, greater<int>> minHeapR, minHeapL;
    priority_queue<int> maxHeapR, maxHeapL;

    int diff = numeric_limits<int>::max();
    int count = 0;

    // Initialize the heaps with the first K elements from the left and right
    for (int i = 0; i < K; ++i) {
        minHeapR.push(A[i]);
        maxHeapR.push(-A[i]); // maxHeap stores negative values to simulate max heap with min heap structure
    }

    for (int i = N - 1; i >= N - K; --i) {
        minHeapL.push(A[i]);
        maxHeapL.push(-A[i]);
    }

    // Traverse the array from the middle to the edge
    for (int i = K; i <= N - K; ++i) {
        // Calculate the current difference between max and min of the combined heaps
        diff = min(diff, max(-maxHeapR.top(), maxHeapL.top() - (-minHeapR.top())));

        // Update the heaps: remove the element that's no longer in the range and add a new one
        minHeapR.pop();
        maxHeapR.pop();
        minHeapL.pop();
        maxHeapL.pop();

        if (i < N - K) {
            minHeapR.push(A[i + K]);
            maxHeapR.push(-A[i + K]);
        }
        if (i > K) {
            minHeapL.push(A[i - K]);
            maxHeapL.push(-A[i - K]);
        }
    }

    // Calculate the final answer after considering all positions
    diff = min(diff, max(-maxHeapR.top(), maxHeapL.top() - (-minHeapR.top())));
    cout << diff << endl;

    return 0;
}