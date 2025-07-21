#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long min_additional_votes(long long total_votes, long long required_votes, long long current_votes) {
    if (current_votes >= required_votes) return 0;
    return max(required_votes - current_votes - 1, 0LL);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + votes[i];
    }

    vector<long long> min_needed(N);
    for (int i = 0; i < N; ++i) {
        long long needed = K - prefix_sum[N] + prefix_sum[i + 1];
        if (needed < 0) needed = 0;
        min_needed[i] = min_additional_votes(K, needed, votes[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << min_needed[i] << " ";
    }
    cout << endl;

    return 0;
}