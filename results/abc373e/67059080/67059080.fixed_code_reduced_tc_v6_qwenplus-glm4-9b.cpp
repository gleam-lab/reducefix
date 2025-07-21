#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    // Sort candidates by votes in descending order
    sort(A.rbegin(), A.rend());

    // Calculate the current votes sum
    ll current_votes = accumulate(A.begin(), A.end(), 0LL, [](ll acc, const pair<ll, int>& p) { return acc + p.first; });

    // Calculate the votes needed to guarantee a win for each candidate
    vector<ll> votes_needed(N);
    for (int i = 0; i < N; ++i) {
        // Maximum votes that others can get
        ll max_other_votes = (i < M ? 0 : A[i - M].first) + K - current_votes;
        
        // Votes needed to guarantee a win
        votes_needed[i] = M * (A[i].first + K - current_votes) - max_other_votes;
    }

    // Adjust the votes_needed for each candidate
    for (int i = 0; i < N; ++i) {
        if (i == 0 || votes_needed[i] >= votes_needed[i - 1]) {
            votes_needed[i] = max(votes_needed[i] - (i + 1), 0LL);
        } else {
            votes_needed[i] = A[i].first + M * (K - current_votes) - (votes_needed[i - 1] - (i + 1));
        }
    }

    // Subtract the votes already received from the votes_needed
    for (auto& v : votes_needed) {
        v = max(0LL, v - A[v].first);
    }

    // Output the results
    for (const auto& v : votes_needed) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}