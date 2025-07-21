#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;
vector<ll> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining_votes = K - prefix[N];

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];

        // Find the position in sorted array where elements are > current
        auto it = upper_bound(sorted_A.begin(), sorted_A.end(), current);
        int cnt_greater = sorted_A.end() - it;

        if (cnt_greater < M) {
            res[i] = 0;
            continue;
        }

        // Binary search for the minimal X such that after adding X to current,
        // the number of candidates with > current + X is < M
        ll low = 0, high = remaining_votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;

            // Find the smallest index where sorted_A[i] > new_val
            it = upper_bound(sorted_A.begin(), sorted_A.end(), new_val);
            cnt_greater = sorted_A.end() - it;

            if (cnt_greater < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Check if answer is feasible (total votes used <= remaining_votes)
        if (answer != -1) {
            res[i] = answer;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}