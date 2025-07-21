#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        // Binary search to find the k-th closest point
        // We need to find the k-th smallest |a[i] - b|
        // To do this, we can use a binary search on the possible distances
        // But a better way is to find the k-th element in the sorted list of distances
        // However, calculating all distances is O(N), which is too slow for Q=1e5
        // Instead, we can use the fact that the distances are sorted if we consider the points around b
        // So we can binary search the position where the distances are less than or equal to a certain value
        // But this is not straightforward
        // Instead, we can use the following approach:
        // The k-th closest point will be among the first k points to the left or right of b in the sorted array
        // So we can find the lower and upper bounds around b and pick the k-th smallest distance
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        int l = pos - 1, r = pos;
        vector<int> candidates;
        for (int i = 0; i < k; i++) {
            if (l >= 0 && (r >= N || b - a[l] <= a[r] - b)) {
                candidates.push_back(a[l]);
                l--;
            } else {
                candidates.push_back(a[r]);
                r++;
            }
        }
        cout << abs(b - candidates[k - 1]) << '\n';
    }
    
    return 0;
}