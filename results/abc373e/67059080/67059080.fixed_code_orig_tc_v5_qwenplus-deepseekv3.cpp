#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[idx[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = sorted_A[i];
        ll low = 0;
        ll high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll new_val = current + mid;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_val);
            int cnt = sorted_A.end() - it;

            if (cnt < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer != -1) {
            res[idx[i]] = answer;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}