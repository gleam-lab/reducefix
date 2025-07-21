#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], b[N], c[N];

bool can_win_with_x(int x, int candidate_index) {
    int votes_needed = m - 1; // Number of candidates that need to have fewer or equal votes than candidate_index
    int current_votes = a[candidate_index];

    if (current_votes + x < votes_needed) {
        return false; // Not enough votes to even be in the top M
    }

    int votes_from_left = 0;
    for (int i = 0; i < candidate_index; ++i) {
        votes_from_left += a[i];
    }

    int votes_from_right = 0;
    for (int i = candidate_index + 1; i < n; ++i) {
        votes_from_right += a[i];
    }

    int remaining_votes = k - votes_from_left - votes_from_right;
    int votes_needed_to_be_in_top_m = x + votes_needed - current_votes;

    if (votes_needed_to_be_in_top_m <= remaining_votes) {
        return true; // Candidate can secure victory with x additional votes
    }

    return false; // Not enough votes to secure victory
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n); // Sort to easily find the top M candidates

    for (int i = 0; i < n; ++i) {
        if (i < m - 1 || (i == m - 1 && can_win_with_x(k - a[i] - (m - 1), i))) {
            cout << "0 ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}