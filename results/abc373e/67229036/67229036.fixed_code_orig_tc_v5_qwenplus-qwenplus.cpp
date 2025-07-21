#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], sorted_a[N];

bool canElect(int idx, int X) {
    // Create a copy of the current votes and add X to candidate idx
    vector<int> votes;
    for (int i = 0; i < n; ++i)
        votes.push_back(a[i]);
    votes[idx] += X;

    // Sort in descending order
    vector<int> sorted_votes = votes;
    sort(sorted_votes.rbegin(), sorted_votes.rend());

    // Count how many candidates have strictly more votes than votes[idx]
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (sorted_votes[i] > votes[idx]) {
            cnt++;
        }
    }

    return cnt < m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> result(n);

    // Pre-sort original array to help with binary search
    for (int i = 0; i < n; ++i)
        sorted_a[i] = a[i];
    sort(sorted_a, sorted_a + n);

    for (int i = 0; i < n; ++i) {
        int low = 0, high = k;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if giving mid extra votes guarantees win
            a[i] += mid;
            int count_more = 0;

            // Binary search to find how many candidates have more votes
            // than a[i] after adding mid
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (a[j] > a[i]) {
                    count_more++;
                }
            }

            if (count_more < m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

            // Undo the change
            a[i] -= mid;
        }

        if (ans == -1 || ans > k)
            result[i] = -1;
        else
            result[i] = max(0LL, ans);
    }

    for (int i = 0; i < n; ++i)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}