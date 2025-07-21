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
    for (int i = 0; i <= n - k; i++) {
        int max_val = A[i + k - 1];
        int min_val = A[i];
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;
    return 0;
}