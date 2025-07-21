#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int &i : a) cin >> i;
    
    // If k is odd, remove the largest element from the start
    if (k % 2 == 1) {
        nth_element(a.begin(), a.begin() + k, a.end()); // O(N)
        a.erase(a.begin() + k, a.begin() + k + 1); // O(N)
    } else {
        // Use min-heap to remove the k smallest elements
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < k; ++i) min_heap.push(a[i]);
        
        for (int i = k; i < n; ++i) {
            if (min_heap.top() < a[i]) {
                min_heap.pop();
                min_heap.push(a[i]);
            }
        }
        
        // Remove the k smallest elements from the end of the array
        a.erase(unique(a.begin(), a.end(), [min_heap] (int val) {
            return min_heap.top() <= val;
        }), a.end());
    }
    
    // Calculate max and min
    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    
    cout << max_val - min_val << endl;
    
    return 0;
}