#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates by the number of votes they currently have
    vector<pair<long long, int>> candidates;
    for (int i = 0; i < n; ++i) {
        candidates.emplace_back(a[i], i);
    }
    sort(candidates.begin(), candidates.end());

    // Calculate prefix sums of sorted votes
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        long long target_votes = candidates[i].first + k / (n - i - 1) + (k % (n - i - 1) != 0);

        // Binary search to find the smallest number of additional votes needed
        int left = 0, right = k;
        while (left <= right) {
            int mid = (left + right) / 2;
            int lid = n - m - (i >= n - m ? 1 : 0);
            long long cnt = 0;

            if (candidates[i].second + mid + 1 > candidates[lid].first) {
                cnt += (candidates[i].second + mid + 1 - candidates[lid].first) * (n - i - 1);
            }

            if (lid <= i && i < lid + (n - i - 1)) {
                cnt--;
            } else {
                cnt += mid;
            }

            if (cnt > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (right == k) {
            ans[candidates[i].second] = -1;
        } else {
            ans[candidates[i].second] = right;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}