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

    // We will consider removing i elements from the front and (k - i) from the back
    // For each possible i in [0, k], we consider the subarray from i to (n - 1 - (k - i)) = n - k + i - 1
    // So the window is from i to (n - k + i - 1), length = n - k
    // We want to find such a window of size n - k with minimal (max - min)

    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    for (int i = 0; i <= k; ++i) {
        int end = i + window_size - 1;
        if (end >= n) break;
        int max_val = *max_element(A.begin() + i, A.begin() + end + 1);
        int min_val = *min_element(A.begin() + i, A.begin() + end + 1);
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;
    return 0;
}