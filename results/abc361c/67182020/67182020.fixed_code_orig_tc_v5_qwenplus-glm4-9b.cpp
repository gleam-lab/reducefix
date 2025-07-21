#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    // Initialize the minimum possible range to a large value
    long long min_range = LLONG_MAX;
    
    // Calculate the possible ranges for even and odd K
    if (K % 2 == 0) {
        // For even K, remove m elements from the top and m elements from the bottom
        int m = K / 2;
        for (int i = m; i < N - m; ++i) {
            min_range = min(min_range, (long long)A[i + m] - (long long)A[i - m]);
        }
    } else {
        // For odd K, remove m+1 elements from the top and m elements from the bottom
        int m = K / 2;
        for (int i = m; i < N - m; ++i) {
            min_range = min(min_range, (long long)A[i + m + 1] - (long long)A[i - m]);
        }
        // Also consider the case where both the highest and lowest elements are removed
        min_range = min(min_range, (long long)A[0] - (long long)A[N - 1]);
    }
    
    cout << min_range << endl;
    return 0;
}