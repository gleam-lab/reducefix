#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end(), greater<int>());

    int threshold = (m <= n) ? sorted_a[m - 1] : 0;

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
        int current = a[i];
        if (m == n) {
            res[i] = 0;
            continue;
        }
        if (current >= threshold) {
            res[i] = 0;
            continue;
        }
        int required = threshold - current + 1;
        if (k < required) {
            res[i] = -1;
            continue;
        }
        int low = 0, high = k, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int new_votes = current + mid;
            vector<int> temp = a;
            temp[i] = new_votes;
            sort(temp.begin(), temp.end(), greater<int>());
            if (temp[m - 1] <= new_votes) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res[i] = ans;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}