#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<pair<int, int>> AB;
    for (int i = 0; i < n; i++) {
        AB.emplace_back(A[i], B[i]);
    }
    sort(AB.begin(), AB.end());

    int min_value = INT_MAX;
    int prefix_sum = 0;
    for (int i = 0; i <= n - k; i++) {
        int sumB = 0;
        for (int j = i; j < i + k && j < n; j++) {
            sumB += AB[j].second;
        }
        int maxA = AB[i + k - 1].first;
        min_value = min(min_value, maxA * sumB);
    }
    return min_value;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        cout << solve(N, K, A, B) << endl;
    }
    return 0;
}