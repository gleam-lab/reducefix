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
    
    vector<ll> sortedA = A;
    sort(all(sortedA));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = K - (prefix[N] - prefix[0]);
        ll res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            
            int pos = upper_bound(all(sortedA), total) - sortedA.begin();
            if (N - pos < M) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (res != -1 && res <= (K - (prefix[N] - prefix[0]))) {
            ans[i] = res;
        } else {
            ans[i] = -1;
        }
    }
    
    // Check if candidates are already elected
    vector<ll> temp = A;
    sort(all(temp), greater<ll>());
    ll threshold = (M <= N) ? temp[M - 1] : 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > threshold) {
            ans[i] = 0;
        } else if (A[i] == threshold && M > 1 && temp[M - 1] == threshold) {
            // Need to check if there are exactly M candidates with >= threshold votes
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > threshold) ++cnt;
            }
            if (cnt < M) {
                ans[i] = 0;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}