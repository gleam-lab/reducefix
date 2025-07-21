#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<ll, ll>;
using PQ = priority_queue<P, vector<P>, greater<P>>;

constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        // Use a min-heap to keep track of the largest k elements of B and their corresponding A elements
        PQ pq;
        ll ans = LINF;
        for (int i = 0; i < k; ++i) {
            pq.push({A[i], B[i]});
        }
        ll sumB = 0;
        while (!pq.empty()) {
            auto [maxA, summB] = pq.top();
            pq.pop();
            sumB += summB;
            ans = min(ans, maxA * sumB);
        }

        cout << ans << '\n';
    }
    return 0;
}