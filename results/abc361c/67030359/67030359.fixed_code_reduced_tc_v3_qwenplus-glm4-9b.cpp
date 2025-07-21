#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array
    sort(A.begin(), A.end());
    
    // The initial range will be the smallest range of length K
    int right = K - 1, left = 0;
    int min_diff = A[right] - A[left];
    
    // Expand the range to the right, keeping the size of the window constant
    while (right < N - 1) {
        if (A[right + 1] - A[left] < min_diff) {
            min_diff = A[right + 1] - A[left];
        }
        if (right - left + 1 < K) {
            right++;
        } else {
            left++;
            if (left == right) { // If left and right meet, expand right
                right++;
            }
        }
    }
    
    // Include the largest possible window of length K
    if (N - (K - 1) - (K - 1) < K) {
        min_diff = min(min_diff, A[N - 1] - A[N - K]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}