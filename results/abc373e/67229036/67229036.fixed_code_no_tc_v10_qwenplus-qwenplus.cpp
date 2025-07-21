#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 100000 + 5;

int n, m, k;
int a[N];
int sorted_a[N];

bool is_electable(int idx, int additional) {
    int target = a[idx] + additional;
    
    // We want to determine if candidate idx can guarantee election regardless of how other votes are distributed.
    // For that, we need to assume the worst-case distribution:
    // - M-1 candidates get just enough to be above this candidate
    // - Remaining candidates get as much as possible without surpassing the top M-1
    
    // To compute this efficiently, we sort all other candidates and greedily assign minimal votes needed to at most (M-1) candidates to beat our candidate.

    // Copy sorted array and modify it to exclude current candidate
    int others[n];
    int oidx = 0;
    for (int i = 0; i < n; ++i)
        if (i != idx)
            others[oidx++] = a[i];
    
    sort(others, others + oidx, greater<int>());

    int used = 0;
    int cnt = 0;

    // Try to raise up to M-1 candidates above target
    for (int i = 0; i < oidx && cnt < m; ++i) {
        if (others[i] < target) {
            used += (target - others[i]);
            ++cnt;
        } else {
            ++cnt;
        }
    }

    return used <= k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> res(n);

    for (int i = 0; i < n; ++i) {
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (is_electable(i, mid))
                r = mid;
            else
                l = mid + 1;
        }

        if (l <= k)
            res[i] = l;
        else
            res[i] = -1;
    }

    for (int x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}