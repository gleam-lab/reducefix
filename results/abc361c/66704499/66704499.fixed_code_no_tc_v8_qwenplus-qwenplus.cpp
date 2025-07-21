#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will try to keep (n - K) elements in B
    int window_size = n - k;
    
    // Sort the array to find candidate min-max ranges
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // We need to find the minimum difference of size window_size in the sorted array
    long long min_diff = 1e18;
    for (int i = 0; i + window_size <= n; ++i) {
        min_diff = min(min_diff, (long long)(sorted_A[i + window_size - 1] - sorted_A[i]));
    }

    cout << min_diff << endl;

    return 0;
}