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

    // Calculate the middle index
    int mid = n / 2;
    int left = mid;
    int right = mid + (n % 2 == 1 ? 0 : 1);

    // Calculate min/max for both cases
    int min_diff_case1 = A[mid + k] - A[mid - k + 1];
    int min_diff_case2 = A[n - k] - A[n - right - k + 1];

    // Output the minimum difference
    cout << min(min_diff_case1, min_diff_case2) << endl;

    return 0;
}