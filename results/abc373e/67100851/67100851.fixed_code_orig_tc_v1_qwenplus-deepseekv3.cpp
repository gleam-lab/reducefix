#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].a;
        candidates[i].idx = i;
    }

    // Sort candidates in descending order of a
    sort(candidates.begin(), candidates.end(), [](const Candidate &x, const Candidate &y) {
        return x.a > y.a;
    });

    vector<ll> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = candidates[i].a;
    }

    vector<ll> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i];
    }

    ll totalUsed = prefixSum[N];
    ll remaining = K - totalUsed;
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll currentA = sortedA[i];
        int pos = i; // current position in the sorted array

        if (pos < M) {
            // Already in top M, no need for additional votes
            res[candidates[i].idx] = 0;
            continue;
        }

        // Binary search to find the minimal X
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll newA = currentA + mid;

            // Find the first position where a candidate's vote is <= newA
            int newPos = upper_bound(sortedA.begin(), sortedA.end(), newA, greater<ll>()) - sortedA.begin();
            
            if (newPos <= M - 1) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer != -1) {
            // Check if the required X is within the remaining votes
            if (answer <= remaining) {
                res[candidates[i].idx] = answer;
            } else {
                res[candidates[i].idx] = -1;
            }
        } else {
            res[candidates[i].idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}