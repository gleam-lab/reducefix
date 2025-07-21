#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, sum, cnt, a[N], b[N], c[N];
int ans[N];

bool check(int x, int y) {
    if (y < 0) return false;
    if (x > k - y) return false;
    
    int ranking = upper_bound(b, b + n, x) - b; // Candidates with more than x votes
    int more_than_x_votes = ranking - n; // Candidates with more than x votes
    if (more_than_x_votes > m) return false;

    int total_votes = x + y;
    int votes_to_left = total_votes - c[m - 1];
    if (votes_to_left < 0) return false;

    int votes_to_right = votes_to_left - (c[n - 1] - c[n - more_than_x_votes - 1]);
    if (votes_to_right > k - total_votes) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        c[i] = c[i - 1] + b[i];
    }

    for (int i = 0; i < n; i++) {
        int l = k + 1, r = 1e12;
        while (l - r > 1) {
            int mid = (l + r) / 2;
            if (check(a[i], mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (l <= k) {
            ans[i] = l;
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}