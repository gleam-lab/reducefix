#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<long long> result(N, -1);
    long long remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);

    for (long long i = 0; i < N; ++i) {
        long long target_rank = M + 1;
        if (target_rank >= N) {
            result[i] = 0;
            continue;
        }

        long long target_vote_count = A[N - target_rank];
        long long needed_votes = target_vote_count + 1 - A[i];

        if (needed_votes <= remaining_votes) {
            result[i] = needed_votes;
        }
    }

    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}