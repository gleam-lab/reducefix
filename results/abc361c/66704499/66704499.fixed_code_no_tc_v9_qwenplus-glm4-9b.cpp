#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
    }

    // Sort the array
    sort(A.begin(), A.end());

    // The minimum range difference will be achieved by removing the k smallest or largest elements
    // Therefore, we are interested in the max difference between the min element of the remaining and the max element of the remaining
    // This can be found by either removing the largest k elements or the smallest k elements
    int min_val = A[n - k];  // Minimum value after removing the largest k elements
    int max_val = A[k - 1];  // Maximum value after removing the smallest k elements

    // Output the minimum possible value of the maximum minus the minimum of B
    cout << max_val - min_val << endl;

    return 0;
}