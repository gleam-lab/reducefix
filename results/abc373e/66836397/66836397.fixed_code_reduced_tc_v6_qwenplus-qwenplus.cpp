#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, x, limit) for (int i = (x); i < (limit); i++)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << " \n"[i + 1 == n]

const ll infl = 1LL << 60;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    // Prepare sorted copy of A
    vector<ll> sortedA = A;
    sort(all(sortedA));

    // Build prefix sum of sortedA
    vector<ll> prefix(N + 1, 0);
    for (ll i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sortedA[i];

    // For each candidate, binary search on required votes
    vector<ll> res(N);
    for (ll i = 0; i < N; ++i) {
        ll low = 0, high = remaining + 1;
        while (low + 1 < high) {
            ll mid = (low + high) / 2;

            ll curr = A[i] + mid;
            // Find how many candidates have strictly more than curr
            auto it = upper_bound(all(sortedA), curr);
            ll numHigher = N - (it - sortedA.begin());

            if (numHigher >= M) {
                low = mid;
            } else {
                high = mid;
            }
        }

        // Now check if we can make sure at most M-1 candidates have more
        // by possibly increasing some others to just below current value
        ll need = low;
        ll curr = A[i] + need;
        vector<ll> B = A;
        B[i] = curr;

        // Count how many candidates have more than curr
        ll countMore = 0;
        for (ll j = 0; j < N; ++j)
            if (j != i && B[j] > curr)
                countMore++;

        if (countMore < M) {
            res[i] = need;
        } else {
            // Need to increase curr until at least M candidates don't have more
            // We'll find the (N-M+1)-th largest vote count excluding i
            vector<ll> others;
            for (ll j = 0; j < N; ++j)
                if (j != i)
                    others.push_back(A[j]);

            sort(rall(others));
            ll threshold;
            if (others.size() >= M)
                threshold = others[M - 1];
            else
                threshold = 0;

            if (threshold >= curr) {
                ll extraNeed = threshold - curr + 1;
                if (need + extraNeed <= remaining)
                    res[i] = need + extraNeed;
                else
                    res[i] = -1;
            } else {
                res[i] = need;
            }
        }
    }

    for (ll i = 0; i < N; ++i)
        print(res[i]);
}