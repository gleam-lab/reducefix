#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-indexed

        // Find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();

        // We'll collect distances from nearby points around b
        vector<ll> dists;
        
        // Add points from left (decreasing index) and right (increasing index)
        int left = pos - 1, right = pos;
        
        // Get up to N nearest neighbors
        while ((left >= 0 || right < N) && dists.size() <= k) {
            if (left >= 0 && right < N) {
                ll d_left = abs(a[left] - b);
                ll d_right = abs(a[right] - b);
                if (d_left <= d_right) {
                    dists.push_back(d_left);
                    left--;
                } else {
                    dists.push_back(d_right);
                    right++;
                }
            } else if (left >= 0) {
                dists.push_back(abs(a[left] - b));
                left--;
            } else {
                dists.push_back(abs(a[right] - b));
                right++;
            }
        }

        // If we haven't collected enough, continue until we have at least k+1
        while (dists.size() <= static_cast<size_t>(k)) {
            if (left >= 0) {
                dists.push_back(abs(a[left] - b));
                left--;
            } else if (right < N) {
                dists.push_back(abs(a[right] - b));
                right++;
            }
        }

        // Sort only the collected distances
        sort(dists.begin(), dists.end());
        cout << dists[k] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}