#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total = 0;
    for (ll& x : A) {
        cin >> x;
        total += x;
    }

    // Remaining votes
    ll rem = K - total;

    // Sort the array to help with comparisons
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    // Compute prefix sums of sortedA
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sortedA[i];

    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = rem;
        bool possible = false;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll curr = A[i] + mid;

            // Find how many candidates have strictly more than curr
            ll pos = lower_bound(sortedA.begin(), sortedA.end(), curr + 1) - sortedA.begin();

            // Number of candidates who could beat us
            ll count = N - pos;

            // If less than M candidates can beat us, then it's good
            if (count < M) {
                possible = true;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (possible)
            result[i] = high + 1;
        else
            result[i] = -1;
    }

    for (ll x : result)
        cout << x << ' ';
    cout << '\n';

    return 0;
}