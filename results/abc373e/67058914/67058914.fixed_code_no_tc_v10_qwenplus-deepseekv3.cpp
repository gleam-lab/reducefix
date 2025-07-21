#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i].first;
    }

    ll total_used = prefix[N];
    ll remaining_votes = K - total_used;

    vector<ll> answer(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = sorted_A[i].first;
        ll low = 0;
        ll high = remaining_votes;
        ll best_X = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;

            // Find the number of candidates with votes > new_votes
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_votes, N), 
                [](const pair<ll, int>& a, const pair<ll, int>& b) {
                    return a.first < b.first;
                });
            int cnt = N - (it - sorted_A.begin());

            if (cnt < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best_X != -1) {
            answer[sorted_A[i].second] = best_X;
        } else {
            answer[sorted_A[i].second] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (answer[i] == -1) {
            // Check if already elected
            ll current_votes = A[i];
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(current_votes, N), 
                [](const pair<ll, int>& a, const pair<ll, int>& b) {
                    return a.first < b.first;
                });
            int cnt = N - (it - sorted_A.begin());
            if (cnt < M) {
                answer[i] = 0;
            }
        }
        cout << answer[i] << ' ';
    }
    cout << endl;

    return 0;
}