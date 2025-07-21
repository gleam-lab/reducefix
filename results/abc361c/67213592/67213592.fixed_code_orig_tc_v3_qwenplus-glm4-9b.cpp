#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap to store the K largest elements
    priority_queue<int, vector<int>, less<int>> max_heap; // Max-heap to store the K smallest elements
    
    for (int i = 0; i < n; ++i) {
        // Add current element to the appropriate heap
        if (max_heap.size() < k) {
            max_heap.push(A[i]);
        } else {
            // If max_heap is full, remove the smallest element if it's less than current element
            if (min_heap.empty() || A[i] > min_heap.top()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            min_heap.push(A[i]);
        }
        
        // Add current element to the appropriate heap
        if (min_heap.size() < k) {
            min_heap.push(A[i]);
        } else {
            // If min_heap is full, remove the largest element if it's greater than current element
            if (max_heap.empty() || A[i] < max_heap.top()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            max_heap.push(A[i]);
        }
    }
    
    // The answer is the difference between the smallest and largest elements in the heaps
    cout << max_heap.top() - min_heap.top() << endl;
    return 0;
}