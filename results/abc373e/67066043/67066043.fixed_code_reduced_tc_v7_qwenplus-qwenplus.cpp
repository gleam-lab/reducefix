#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Create sorted version of A to help with calculations
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> ans(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = K;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = current + mid;

            // Binary search to find how many candidates have strictly more votes than target
            int count = N - (upper_bound(all(sorted_A), target) - sorted_A.begin());

            if (count < M) {
                // We are in top M, can win
                high = mid - 1;
            } else {
                // Not enough votes yet
                low = mid + 1;
            }
        }

        // Check if it's possible to win
        ll final_target = current + low;
        int count = N - (upper_bound(all(sorted_A), final_target) - sorted_A.begin());

        if (count < M && low <= K)
            ans[i] = low;
        else
            ans[i] = -1;
    }

    // Set answer to 0 for already winning candidates
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll count = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (A[j] > current) count++;
        }
        if (count < M) ans[i] = 0;
    }

    for (ll x : ans)
        cout << x << ' ';
    cout << '\n';
}