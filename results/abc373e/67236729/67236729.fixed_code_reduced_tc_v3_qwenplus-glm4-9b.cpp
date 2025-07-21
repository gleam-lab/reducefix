#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    vector<int> A;
    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    vector<int> indices(N);
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return A[a] > A[b];
    });

    vector<int> additional_votes(N, -1);
    long long sum_A = accumulate(A.begin(), A.end(), 0LL);
    vector<long long> prefix_sum(N);
    prefix_sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    long long max_votes_needed = 0;
    for (int i = 0; i < M - 1; ++i) {
        max_votes_needed = max(max_votes_needed, prefix_sum[i] + 2 * M - 1);
    }

    if (max_votes_needed > K - sum_A) {
        cout << "0 ";
        for (int i = 1; i < N; ++i) {
            cout << "-1 ";
        }
        cout << endl;
        return 0;
    }

    for (int i = 0; i < M - 1; ++i) {
        int idx = indices[i];
        long long votes_needed = max_votes_needed - prefix_sum[i] - (M - 1);
        if (votes_needed <= K - sum_A - prefix_sum[i + 1]) {
            additional_votes[idx] = votes_needed;
        }
    }

    cout << "0 ";
    for (int i = 0; i < N; ++i) {
        if (additional_votes[i] == -1) {
            cout << "-1 ";
        } else {
            cout << additional_votes[i] << " ";
        }
    }
    cout << endl;

    return 0;
}