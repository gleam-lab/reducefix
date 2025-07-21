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
    }

    vector<ll> results(N);
    
    // We need to process each candidate
    for (int i = 0; i < N; ++i) {
        ll need = 0;
        // Count how many candidates have more votes than current one
        int stronger = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (A[j] > A[i]) {
                stronger++;
            }
        }
        
        if (stronger < M) {
            results[i] = 0; // Already elected
            continue;
        }

        // Need to overtake enough candidates to reduce the count of stronger candidates below M
        vector<ll> others;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            others.push_back(A[j]);
        }

        sort(others.begin(), others.end());
        ll extra = 0;
        bool possible = false;

        // Binary search on minimal X such that after getting X votes, candidate i is elected
        ll low = 0, high = K;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i] + mid;
            // Find how many candidates have votes > new_vote
            // Use binary search since others are sorted
            int idx = distance(others.begin(), upper_bound(others.begin(), others.end(), new_vote));
            if (idx >= M) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (low <= K) {
            results[i] = low;
        } else {
            results[i] = -1; // Not possible
        }
    }

    for (auto &res : results) {
        cout << res << " ";
    }
    cout << "\n";

    return 0;
}