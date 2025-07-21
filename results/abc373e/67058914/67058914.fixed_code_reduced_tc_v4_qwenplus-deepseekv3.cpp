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

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i].first;
    }

    ll remaining_votes = K - prefix[N];

    vector<ll> answer(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current_votes = sortedA[i].first;
        ll low = 0;
        ll high = remaining_votes;
        ll best = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll new_votes = current_votes + mid;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_votes, N));
            int count_above = sortedA.end() - it;
            if (count_above < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        answer[sortedA[i].second] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << answer[i] << ' ';
    }

    return 0;
}