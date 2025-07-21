#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    ll remaining = K - sum_A;

    vector<pair<ll, int>> sorted(N);
    for (int i = 0; i < N; ++i) {
        sorted[i] = {A[i], i};
    }
    sort(sorted.begin(), sorted.end(), greater<pair<ll, int>>());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted[i].first;
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll a_i = sorted[i].first;
        int pos = i;

        ll low = 0, high = remaining, res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a_i = a_i + mid;

            int left = 0, right = N;
            while (left < right) {
                int mid_pos = (left + right) / 2;
                if (sorted[mid_pos].first > new_a_i) {
                    left = mid_pos + 1;
                } else {
                    right = mid_pos;
                }
            }
            int rank = left;

            if (rank < M) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (res != -1) {
            ans[sorted[i].second] = res;
        } else if (i < M) {
            ans[sorted[i].second] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            cout << 0 << ' ';
        } else {
            cout << ans[i] << ' ';
        }
    }
    cout << endl;

    return 0;
}