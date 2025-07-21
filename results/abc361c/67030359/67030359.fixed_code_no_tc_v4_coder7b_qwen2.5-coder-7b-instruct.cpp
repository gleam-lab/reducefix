#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to facilitate finding the optimal subarray
    sort(A.begin(), A.end());
    
    // Initialize the minimum difference with a large value
    ll min_diff = LLONG_MAX;
    
    // Iterate over all possible starting positions for the subarray
    for (int start = 0; start <= N - K; ++start) {
        // Calculate the end position of the subarray
        int end = start + K;
        // Calculate the difference between the max and min values in the subarray
        ll current_diff = A[end - 1] - A[start];
        // Update the minimum difference found so far
        min_diff = min(min_diff, current_diff);
    }
    
    // Output the result
    cout << min_diff << endl;
    
    return 0;
}