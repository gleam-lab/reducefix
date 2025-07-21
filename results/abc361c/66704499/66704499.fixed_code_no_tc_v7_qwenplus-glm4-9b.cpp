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

    // Sort the array
    sort(A.begin(), A.end());

    // If k is less than half the size of the array, remove the smallest k elements
    // Otherwise, remove the largest k elements
    int remove_from_end = (k <= n / 2);
    vector<int> remaining(A.begin() + remove_from_end * k, A.end() - (n - k - remove_from_end) * k);

    // Output the difference between the max and min of the remaining elements
    cout << *max_element(remaining.begin(), remaining.end()) - *min_element(remaining.begin(), remaining.end()) << endl;

    return 0;
}