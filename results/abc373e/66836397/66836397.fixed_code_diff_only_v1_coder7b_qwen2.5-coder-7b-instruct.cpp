#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> A = a;
    sort(A.rbegin(), A.rend());

    vector<ll> prefix_sum(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    vector<ll> result(n, -1);
    for (ll i = 0; i < n; ++i) {
        ll needed_votes = 0;
        ll rank = i + 1;
        ll upper_bound = prefix_sum[n] - prefix_sum[i];
        ll lower_bound = prefix_sum[i];

        if (rank > m) {
            needed_votes = max(needed_votes, A[i] - lower_bound + 1);
        }

        ll remaining_votes = K - sum;
        if (remaining_votes >= needed_votes) {
            result[i] = needed_votes;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}