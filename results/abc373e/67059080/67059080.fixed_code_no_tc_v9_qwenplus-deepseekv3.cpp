#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return A[i] > A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[indices[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll original_pos = i;
        ll original_votes = sorted_A[i];
        ll low = 0;
        ll high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = original_votes + mid;
            ll position = original_pos;

            // Find the first candidate in sorted_A that has <= new_votes
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sorted_A[m] > new_votes) {
                    left = m + 1;
                } else {
                    right = m;
                }
            }
            int new_pos = left;

            if (new_pos < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[indices[i]] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;

    return 0;
}