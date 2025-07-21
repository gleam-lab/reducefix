#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        minHeap.push(num);
        maxHeap.push(num);
    }

    // Remove k elements from the sequence
    for (int i = 0; i < k; i++) {
        // Remove the smallest element from the min heap
        minHeap.pop();
        // Remove the largest element from the max heap
        maxHeap.pop();
    }

    // The minimum possible value of the maximum minus the minimum of B
    cout << maxHeap.top() - minHeap.top() << endl;

    return 0;
}