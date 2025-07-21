#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

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

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    // Sort candidates by current votes
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    // Prefix sum of sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[idx[i]];
    }

    vector<ll> res(N);

    // For each candidate, determine minimum additional votes needed
    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted list
        ll curr = A[idx[i]];

        // Binary search on additional votes needed
        ll low = 0, high = K;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = curr + mid;

            // Find how many candidates have more votes than this total
            int l = pos + 1, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (A[idx[m]] > total)
                    l = m;
                else
                    r = m;
            }

            int stronger = N - l;

            if (stronger < M) {
                // Candidate is elected, try with fewer additional votes
                ans = mid;
                high = mid - 1;
            } else {
                // Not elected in worst-case, need more votes
                low = mid + 1;
            }
        }

        res[idx[i]] = (ans == -1) ? -1 : ans;
        
        // If already elected, set to 0
        if (ans == 0) res[idx[i]] = 0;
    }

    for (ll x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}