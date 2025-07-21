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
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;
    
    vector<int> order(N);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return A[i] < A[j]; });
    
    vector<ll> sortedA = A;
    sort(all(sortedA));
    
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = order[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i] + mid;
            
            int pos = upper_bound(all(sortedA), new_vote) - sortedA.begin();
            int needed = N - M;
            if (pos > needed) {
                ll sum = prefix[pos] - prefix[needed];
                ll required = new_vote * (pos - needed) - sum;
                if (required <= remaining) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                best = mid;
                high = mid - 1;
            }
        }
        ans[i] = best;
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << max(0LL, ans[i]) << " ";
        }
    }
    cout << endl;
    
    return 0;
}