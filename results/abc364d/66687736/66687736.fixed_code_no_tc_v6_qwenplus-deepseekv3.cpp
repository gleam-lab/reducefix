#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    rep(i, q) {
        ll b, k;
        cin >> b >> k;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int pos = right;
        int l = pos, r = pos + 1;
        vi distances;
        while (distances.size() < k && (l >= 0 || r < n)) {
            if (l >= 0 && r < n) {
                if (abs(b - a[l]) <= abs(b - a[r])) {
                    distances.push_back(abs(b - a[l]));
                    l--;
                } else {
                    distances.push_back(abs(b - a[r]));
                    r++;
                }
            } else if (l >= 0) {
                distances.push_back(abs(b - a[l]));
                l--;
            } else {
                distances.push_back(abs(b - a[r]));
                r++;
            }
        }
        cout << distances[k - 1] << "\n";
    }
    return 0;
}