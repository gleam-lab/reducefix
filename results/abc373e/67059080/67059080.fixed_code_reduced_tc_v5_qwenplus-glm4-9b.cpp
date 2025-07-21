#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;

int N, M;
ll K;
ll A[MAXN];

bool can_win(int idx, int add_votes) {
    ll votes_needed = M - 1; // Need M-1 more than us to win
    ll votes_to_win = A[idx] + add_votes;
    ll remaining_votes = K - (A[0] + A[1] + ... + A[N]);
    ll total_votes = votes_to_win + votes_needed;

    ll candidate_votes = votes_to_win;
    ll other_votes = 0;

    for (int j = 0; j < N; ++j) {
        if (j == idx) continue;
        if (candidate_votes + A[j] >= total_votes) return true;
        candidate_votes += A[j];
        other_votes += A[j];
    }

    if (candidate_votes + other_votes >= total_votes) return true;
    for (int j = 0; j < N; ++j) {
        if (j == idx) continue;
        if (candidate_votes + other_votes + A[j] >= total_votes) return true;
        candidate_votes += A[j];
    }

    return false;
}

ll min_votes_needed(int idx) {
    int l = 0, r = K + 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (can_win(idx, mid)) r = mid;
        else l = mid;
    }
    return l;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<ll> votes_needed(N);

    for (int i = 0; i < N; ++i) {
        votes_needed[i] = min_votes_needed(i);
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] + votes_needed[i] >= M) votes_needed[i] = -1;
    }

    for (int i = 0; i < N; ++i) {
        cout << votes_needed[i] << (i < N - 1 ? ' ' : '\n');
    }
    return 0;
}