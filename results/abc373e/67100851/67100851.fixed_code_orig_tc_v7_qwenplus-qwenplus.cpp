#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, M;
ll K;
ll A[MAXN];
ll sortedA[MAXN];
ll prefix[MAXN];

// Binary search helper function to check if 'x' additional votes to candidate at index 'i'
// ensures victory regardless of how remaining votes are distributed
bool isEnough(int i, ll x) {
    ll total = K - x;
    if (total < 0) return false;

    ll target = A[i] + x;

    // Find how many candidates can get more than 'target' votes using the remaining votes
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (sortedA[mid] <= target)
            lo = mid;
        else
            hi = mid - 1;
    }

    int cnt = N - lo - 1;
    if (cnt >= M) return false; // Too many better candidates

    // Try to raise the rest to at most 'target' to minimize number of votes used
    ll used = 0;
    for (int j = N - 1; j > lo && cnt < M; --j) {
        ll need = max(0LL, sortedA[j] - target);
        used += need;
        cnt++;
    }
    
    return used <= total;
}

ll computeMinVotes(int i) {
    ll lo = 0, hi = K;
    ll ans = -1;

    ll original = A[i];
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        A[i] = original + mid;
        if (isEnough(i, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        A[i] = original; // restore
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> indices(N);
    for (int i = 0; i < N; ++i) indices[i] = i;

    // Precompute sorted array
    copy(A, A + N, sortedA);
    sort(sortedA, sortedA + N);
    prefix[0] = 0;
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + sortedA[i - 1];
    }

    vector<ll> res(N);

#pragma omp parallel for // Optional: for faster performance on multi-core systems
    for (int i = 0; i < N; ++i) {
        ll already_win = 0;
        ll low = 0, high = K;
        ll ans = -1;

        // Check if already a winner
        A[i] += 0;
        bool ok = isEnough(i, 0);
        if (ok) {
            res[i] = 0;
            continue;
        }

        // Binary search
        while (low <= high) {
            ll mid = (low + high) / 2;
            A[i] += mid;
            bool good = isEnough(i, mid);
            A[i] -= mid;

            if (good) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = (ans == -1 ? -1 : ans);
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}