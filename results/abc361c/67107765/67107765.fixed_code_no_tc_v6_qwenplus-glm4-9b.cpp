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

    // Sort the vector to easily find the smallest and largest elements
    sort(A.begin(), A.end());

    // The minimum difference will be between the maximum of the first k-1 elements
    // and the minimum of the last n-k elements, or the minimum between the maximum
    // of the first k elements and the minimum of the last n-k-1 elements.
    int min diff = min((long long)A[k-1] - A[0], (long long)A[k] - A[1]);

    cout << diff << endl;

    return 0;
}