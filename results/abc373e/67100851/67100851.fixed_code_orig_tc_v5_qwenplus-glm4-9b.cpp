#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    vector<pair<long long, int>> A; // Pair of votes and index
    cin >> N >> M >> K;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    // Sort candidates by votes in descending order
    sort(A.begin(), A.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        return a.first > b.first;
    });

    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].first;
    }

    vector<long long> C(N, -1);
    for (int i = 0; i < N; i++) {
        long long remaining_votes = K - prefix_sum[N];
        long long votes_needed = max(0LL, A[i].first + (long long)M + 1 - prefix_sum[i]);
        long long additional_votes_needed = votes_needed - A[i].first;

        if (additional_votes_needed <= remaining_votes) {
            C[A[i].second] = additional_votes_needed;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}