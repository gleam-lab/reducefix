#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We need to remove k elements to minimize the difference between the max and min
    // of the remaining elements. To do this, we should remove the k largest elements.
    // If k is even, remove the largest k/2 elements from both ends.
    // If k is odd, remove k largest elements from the end.
    int left = (k + 1) / 2; // largest elements to be removed from the left end
    int right = k / 2;      // largest elements to be removed from the right end

    int max_val = *max_element(A.begin() + n - right, A.end()); // max of the remaining elements
    int min_val = *min_element(A.begin() + left, A.begin() + n - right); // min of the remaining elements

    cout << max_val - min_val << endl;

    return 0;
}