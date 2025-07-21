#include<bits/stdc++.h>
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
            if (a[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int i = right;
        int j = right + 1;
        vector<ll> distances;
        for (int cnt = 0; cnt < k && (i >= 0 || j < N); ) {
            if (i >= 0 && j < N) {
                if (abs(a[i] - b) <= abs(a[j] - b)) {
                    distances.push_back(abs(a[i] - b));
                    i--;
                } else {
                    distances.push_back(abs(a[j] - b));
                    j++;
                }
            } else if (i >= 0) {
                distances.push_back(abs(a[i] - b));
                i--;
            } else {
                distances.push_back(abs(a[j] - b));
                j++;
            }
            cnt++;
        }
        
        cout << distances[k - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}