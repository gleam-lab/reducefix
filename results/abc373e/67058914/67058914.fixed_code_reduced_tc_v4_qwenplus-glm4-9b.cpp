#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
vector<ll> A;

ll solve(ll votes, ll x) {
    sort(A.begin(), A.end(), greater<ll>()); // Sort descending
    ll sum = 0, cnt = 0;
    for (ll i = 0; i < N; ++i) {
        if (sum + votes < A[i] + x) {
            return -1; // Impossible to guarantee victory
        }
        sum += A[i] + x;
        ++cnt;
        if (cnt > M) {
            return x; // If we have more than M candidates with more votes, x is sufficient
        }
    }
    return votes - sum + A[N - M]; // Calculate the minimum additional votes needed
}

int main() {
    cin >> N >> M >> K;
    A.resize(N);
    for (ll &a : A) cin >> a;
    
    vector<ll> results(N, -1); // Initialize results with -1
    
    for (ll i = 0; i < N; ++i) {
        ll votes = K - accumulate(A.begin(), A.end(), 0LL); // Remaining votes
        ll min_votes_needed = solve(votes, A[i] + 1); // Solve for A[i] + 1 additional votes
        if (min_votes_needed != -1) {
            results[i] = min_votes_needed - A[i]; // Update result for A[i]
        }
    }
    
    for (ll result : results) {
        cout << result << ' ';
    }
    cout << '\n';
    
    return 0;
}