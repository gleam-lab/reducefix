#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will consider all windows of size (N - K)
    int window_size = N - K;
    int min_diff = INT_MAX;

    // Sliding window approach
    for (int i = 0; i + window_size <= N; ++i) {
        int max_val = *max_element(A.begin() + i, A.begin() + i + window_size);
        int min_val = *min_element(A.begin() + i, A.begin() + i + window_size);
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;
    return 0;
}