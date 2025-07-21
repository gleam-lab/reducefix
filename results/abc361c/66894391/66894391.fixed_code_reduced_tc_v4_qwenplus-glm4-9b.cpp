#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> prefix_min(n, 0), suffix_max(n, 0);

    // Input the sequence
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Compute prefix minimum
    prefix_min[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefix_min[i] = min(prefix_min[i-1], A[i]);
    }

    // Compute suffix maximum
    suffix_max[n-1] = A[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i+1], A[i]);
    }

    // Find minimum possible range
    int min_range = INT_MAX;
    for (int i = k; i <= n - k; i++) {
        int maxVal = max(prefix_min[i-1], suffix_max[i+k-1]);
        int minVal = min(prefix_min[i-1], suffix_max[i+k-1]);
        min_range = min(min_range, maxVal - minVal);
    }

    cout << min_range << endl;
    return 0;
}