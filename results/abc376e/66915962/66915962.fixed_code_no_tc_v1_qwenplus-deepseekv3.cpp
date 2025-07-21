#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<P> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> p[i].second;
        }
        sort(p.begin(), p.end());
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; i++) {
            A[i] = p[i].first;
            B[i] = p[i].second;
        }
        ll ans = LINF;
        priority_queue<ll> pq;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += B[i];
            pq.push(B[i]);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, A[i] * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}