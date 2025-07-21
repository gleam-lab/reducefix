#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long N, M, K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    long long sum_votes = 0;
    for (long long &a : A) {
        cin >> a;
        sum_votes += a;
    }

    vector<pair<long long, long long>> candidates;
    for (int i = 0; i < N; ++i) {
        candidates.emplace_back(A[i], i);
    }
    sort(candidates.begin(), candidates.end());

    vector<long long> result(N);
    for (int i = 0; i < N; ++i) {
        long long votes_needed = 0;
        if (i + 1 < M) {
            votes_needed = candidates[M-1].first - candidates[i].first;
        } else {
            votes_needed = K - sum_votes;
        }
        result[candidates[i].second] = votes_needed;
    }

    for (long long votes : result) {
        cout << votes << " ";
    }
    cout << endl;
    return 0;
}