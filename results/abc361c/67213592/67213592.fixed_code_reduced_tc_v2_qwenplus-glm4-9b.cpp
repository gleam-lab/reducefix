#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    // Create priority queues for the maximum and minimum values
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap_left, min_heap_right;
    
    // Initialize the priority queues with the first K elements
    for (int i = 0; i < k; ++i) {
        max_heap.push(A[i]);
        min_heap_left.push(A[i]);
    }
    
    // Initialize the answer with the difference between the max and min in the first window
    int best_answer = max_heap.top() - min_heap_left.top();
    
    // Iterate through the rest of the array
    for (int i = k; i < n; ++i) {
        // Add the new element to both heaps
        max_heap.push(A[i]);
        min_heap_left.push(A[i]);
        
        // Remove the old element from both heaps if it's still in the window
        while (!min_heap_left.empty() && A[i - k] != min_heap_left.top()) {
            min_heap_left.pop();
        }
        while (!min_heap_right.empty() && A[i - k] != min_heap_right.top()) {
            min_heap_right.pop();
        }
        
        // Update the best answer for the current window
        int current_max = max_heap.top();
        int current_min = (min_heap_left.top() < min_heap_right.top()) ? min_heap_left.top() : min_heap_right.top();
        best_answer = min(best_answer, current_max - current_min);
        
        // Add the old element to the right heap
        min_heap_right.push(A[i - k]);
    }
    
    // Output the best answer
    cout << best_answer << endl;
}