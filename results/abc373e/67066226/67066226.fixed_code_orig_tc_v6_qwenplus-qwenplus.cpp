#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Total remaining votes to distribute
    ll remaining = K - accumulate(all(A), (ll)0);
    
    // We will process each candidate and compute the minimal required additional votes
    vector<ll> result(N, -1);
    
    // Create a sorted copy of A to use in binary search
    vector<int> indices(N);
    iota(all(indices), 0);
    sort(all(indices), [&](int i, int j) { return A[i] < A[j]; });
    
    // Pre-sort the A array to help with prefix sums
    vector<ll> sortedA = A;
    sort(all(sortedA));
    
    // Prefix sum of sortedA
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    for (int idx = 0; idx < N; ++idx) {
        int originalIndex = indices[idx];
        ll currentVotes = A[originalIndex];

        // Binary search on X: number of extra votes needed for this candidate to win
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newScore = currentVotes + mid;

            // Find how many candidates have strictly more than newScore
            ll right = upper_bound(sortedA.begin(), sortedA.end(), newScore) - sortedA.begin();
            ll left = lower_bound(sortedA.begin(), sortedA.end(), newScore + 1) - sortedA.begin();

            ll need = 0;
            if (left < N - M) {
                need = (N - M - left) * (newScore + 1) - (prefix[N] - prefix[left]);
                if (mid == 0 && (N - left) > M) {
                    // Already has enough votes
                    need = 0;
                }
            }

            if (need <= remaining - mid) {
                if (mid <= remaining) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }

        if (answer != -1) {
            result[originalIndex] = answer;
        } else {
            // Check if already among top M
            ll cnt = N - (upper_bound(sortedA.begin(), sortedA.end(), currentVotes) - sortedA.begin());
            if (cnt < M) {
                result[originalIndex] = 0;
            } else {
                result[originalIndex] = -1;
            }
        }
    }

    for (auto &x : result) {
        cout << x << " ";
    }
    cout << '\n';
}