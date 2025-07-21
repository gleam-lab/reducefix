#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
  
    sort(A.begin(), A.end());
  
    int min_diff = INT_MAX;
  
    // Use two pointers
    int left = 0, right = n - 1;
    while (left <= right) {
        int remaining_elements = n - (right - left + 1);
        if (remaining_elements == k) {
            // Check if this range gives a minimum difference
            min_diff = min(min_diff, A[right] - A[left]);
        } else if (remaining_elements < k) {
            // Move the left pointer to the right
            left++;
        } else {
            // Move the right pointer to the left
            right--;
        }
    }
  
    cout << min_diff << endl;
  
    return 0;
}