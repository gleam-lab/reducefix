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

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll total_used = prefix[N];
    ll remaining = K - total_used;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll ai = A[i];
        int pos = lower_bound(sorted_A.begin(), sorted_A.end(), ai, greater<ll>()) - sorted_A.begin();

        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_ai = ai + mid;

            int new_pos = lower_bound(sorted_A.begin(), sorted_A.end(), new_ai, greater<ll>()) - sorted_A.begin();

            if (new_pos < M) {
                answer = mid;
                high = mid - 1;
            } else {
                ll sum = 0;
                if (new_pos > 0) {
                    sum = prefix[M] - (prefix[M] - prefix[new_pos]) + (new_ai * (new_pos - M));
                }

                if (sum + mid <= remaining + total_used) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        res[i] = answer;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}