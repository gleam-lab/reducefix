#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider removing i elements from the front and k-i elements from the back
    // For each possible i in [0, k], we check the subarray A[i..n-1-(k-i)] = A[i..n-k+i-1]
    // The length of this subarray is n - k

    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i <= k; ++i) {
        int left = i;
        int right = n - 1 - (k - i);
        if (right - left + 1 > n - k) {
            // In case of miscalculation, should not happen
            continue;
        }
        min_diff = min(min_diff, A[right] - A[left]);
    }

    cout << min_diff << endl;
}