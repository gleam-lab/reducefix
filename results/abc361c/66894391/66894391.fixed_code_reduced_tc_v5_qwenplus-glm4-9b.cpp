#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Sort the array to easily find the smallest and largest elements
    sort(A.begin(), A.end());

    // If removing the first K elements results in a smaller range, that's the answer
    if (2 * k >= n) {
        cout << A[n - k - 1] - A[k] << endl;
    } else {
        cout << A[n - 1] - A[0] << endl;
    }

    return 0;
}