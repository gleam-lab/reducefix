#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int pos = left;
        int l = pos - 1, r = pos;
        vector<ll> distances;
        while (distances.size() < N) {
            if (l >= 0 && r < N) {
                if (abs(a[l] - b) <= abs(a[r] - b)) {
                    distances.push_back(abs(a[l] - b));
                    l--;
                } else {
                    distances.push_back(abs(a[r] - b));
                    r++;
                }
            } else if (l >= 0) {
                distances.push_back(abs(a[l] - b));
                l--;
            } else if (r < N) {
                distances.push_back(abs(a[r] - b));
                r++;
            }
        }
        
        cout << distances[k - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}