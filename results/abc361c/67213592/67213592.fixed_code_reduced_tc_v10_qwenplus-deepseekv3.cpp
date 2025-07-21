#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& val : A) {
        cin >> val;
    }
    sort(A.begin(), A.end());
    int min_diff = INT_MAX;
    int window_size = N - K;
    for (int i = 0; i + window_size <= N; ++i) {
        int current_diff = A[i + window_size - 1] - A[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}