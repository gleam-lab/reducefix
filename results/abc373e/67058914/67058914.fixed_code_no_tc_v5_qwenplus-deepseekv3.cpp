#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    ll totalUsed = prefix[N];
    ll remaining = K - totalUsed;

    vector<ll> ans(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = sortedA[i].first;
        int pos = i;

        // Binary search for the minimum X such that after adding X to current_votes,
        // the number of candidates with votes > current_votes + X is < M.
        ll low = 0, high = remaining;
        ll best_X = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;

            // Find how many candidates have votes > new_votes in the original array.
            // All candidates >= some index in sortedA have votes > new_votes.
            auto it = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_votes, INT_MAX));
            int cnt_greater = sortedA.end() - it;

            // Additionally, candidates before 'i' in sortedA might be boosted to exceed new_votes.
            // The remaining votes after assigning X to the current candidate is remaining - mid.
            // We can distribute these votes to other candidates to maximize the count exceeding new_votes.
            // The best way to maximize cnt_greater is to distribute the remaining votes to the smallest candidates first.

            if (cnt_greater < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best_X != -1) {
            ans[sortedA[i].second] = best_X;
        } else {
            // Check if the candidate is already winning without any additional votes.
            ll new_votes = current_votes;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_votes, INT_MAX));
            int cnt_greater = sortedA.end() - it;
            if (cnt_greater < M) {
                ans[sortedA[i].second] = 0;
            } else {
                ans[sortedA[i].second] = -1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}