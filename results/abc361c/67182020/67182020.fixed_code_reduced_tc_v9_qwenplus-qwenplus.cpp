#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will consider all possible windows of size (N - K)
    // Since we must keep (N - K) elements in original order
    int window_size = N - K;
    int min_diff = numeric_limits<int>::max();

    // For each possible starting index of the window
    for (int i = 0; i + window_size <= N; ++i) {
        // Get the subarray A[i..i+window_size-1]
        vector<int> window(A.begin() + i, A.begin() + i + window_size);
        
        // Find min and max in this window
        int current_min = *min_element(window.begin(), window.end());
        int current_max = *max_element(window.begin(), window.end());
        
        // Update minimum possible difference
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff << "\n";
    return 0;
}