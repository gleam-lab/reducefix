#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_win(vector<long long>& A, vector<long long>& B, long long k, int m, int n) {
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + B[i];
    }
    for (int i = 0; i < n; ++i) {
        long long remaining_votes = k - prefix_sum[i];
        long long required_votes = A[i] + remaining_votes;
        long long rank = upper_bound(B.begin(), B.end(), required_votes) - B.begin();
        if (rank <= n - m) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_castio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<long long> B(n);
    for (int i = 0; i < n; ++i) {
        B[i] = A[i];
    }

    long long left = 0, right = k;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (can_win(A, B, mid, m, n)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (A[i] + left >= B[i]) {
            cout << 0 << " ";
        } else {
            cout << B[i] - A[i] - left << " ";
        }
    }
    cout << endl;

    return 0;
}