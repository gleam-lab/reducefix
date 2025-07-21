#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total_current = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_current += A[i];
    }
    ll remaining = K - total_current;

    // Create a copy of A to sort and compute prefix sums
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + sorted_A[i - 1];
    }

    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll ans = -1;
        ll a_i = A[i];

        // Binary search on the number of additional votes needed
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_total = a_i + mid;

            // Find how many candidates can be strictly greater than current_total
            // by using binary search in sorted_A
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sorted_A[m] > current_total)
                    right = m;
                else
                    left = m + 1;
            }
            int count_greater = N - left;

            // We need less than M candidates greater than current_total
            if (count_greater < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans == -1) {
            res[i] = -1;
        } else {
            res[i] = ans;
        }
    }

    for (ll x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}