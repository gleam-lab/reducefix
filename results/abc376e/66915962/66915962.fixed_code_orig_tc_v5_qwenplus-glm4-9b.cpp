#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;  // Store original index
        }
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort by A[i] descending
        sort(A.rbegin(), A.rend());

        long long min_value = LLONG_MAX;
        long long sum_B = 0;
        int j = 0;

        // Use two pointers to find the minimum value
        for (int i = 0; i < K; ++i) {
            sum_B += B[A[i].second];
            while (j < N && sum_B < K) {
                sum_B += B[A[j].second];
                j++;
            }
            min_value = min(min_value, (long long)A[i].first * sum_B);
        }

        cout << min_value << '\n';
    }
    return 0;
}