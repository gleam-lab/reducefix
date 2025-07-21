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
    int result = A.back() - A.front(); // Initialize with the maximum possible difference
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = N - 1 - (K - i);
        if (right >= left) {
            int current_diff = A[right] - A[left];
            if (current_diff < result) {
                result = current_diff;
            }
        }
    }
    cout << result << endl;
    return 0;
}