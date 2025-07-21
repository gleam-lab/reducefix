#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
  
    // Read the input values
    for (int &a : A) {
        cin >> a;
    }
  
    // Sort the array to easily find the smallest and largest elements
    sort(A.begin(), A.end());
  
    // Initialize pointers to handle the sliding window
    int left = 0, right = 0;
  
    // This array will store the differences between the maximum and minimum
    // of the remaining elements after removing `k` elements
    vector<int> maxminusmin(n + 1);
  
    // Start by considering all elements removed (right pointer is at n)
    right = n;
    maxminusmin[0] = A[right - 1] - A[left];
 
    // Slide the window across the array
    for (int i = 1; i <= k; i++) {
        // Move the right pointer to minimize the difference
        while (right - left > 1 && A[right - 1] - A[left] >= A[right - 2] - A[left - 1]) {
            right--;
        }
        // Update the array with the new maxminusmin value
        maxminusmin[i] = A[right - 1] - A[left];
        // Move the left pointer to the right to consider one more element
        left++;
    }
  
    // Output the maximum difference found
    cout << *max_element(maxminusmin.begin() + 1, maxminusmin.begin() + k + 1);
    return 0;
}