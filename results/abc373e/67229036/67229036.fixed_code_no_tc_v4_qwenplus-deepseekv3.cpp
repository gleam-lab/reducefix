#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], prefix[N];

bool is_possible(int candidate_index, int x) {
    int current_votes = a[candidate_index] + x;
    int pos = upper_bound(b + 1, b + n + 1, current_votes) - b - 1;
    int rank = n - pos;
    if (rank < m) {
        return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int total_votes = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total_votes += a[i];
        b[i] = a[i];
    }
    int remaining_votes = k - total_votes;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        int low = 0;
        int high = remaining_votes;
        int answer = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (is_possible(i, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (answer != -1) {
            cout << answer << " ";
        } else {
            cout << -1 << " ";
        }
    }
    return 0;
}