#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach
    // We need to keep (N - K) elements
    // So we slide a window of size (N - K) over the array and find min and max in each window
    // Then compute the difference and track minimum overall difference

    // Edge case: if we remove all but one element
    if (N - K == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Use ordered maps to maintain elements in current window
    multiset<int> window(A.begin(), A.begin() + (N - K));
    int min_diff = INT_MAX;

    for (int i = 0; i <= K; ++i) {
        // Window is from i to i + (N-K-1)
        if (i > 0) {
            // Remove previous element and add new one
            window.erase(window.find(A[i - 1]));
            window.insert(A[i + (N - K) - 1]);
        }
        
        // Get min and max from current window
        int current_min = *window.begin();
        int current_max = *(--window.end());
        
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff << endl;
    return 0;
}