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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int min_diff = A[N - 1] - A[0]; // Initialize with the maximum possible difference
    for (int i = 0; i <= K; ++i) {
        int j = N - K + i - 1;
        if (j >= i) {
            min_diff = min(min_diff, A[j] - A[i]);
        }
    }
    cout << min_diff << endl;
    return 0;
}