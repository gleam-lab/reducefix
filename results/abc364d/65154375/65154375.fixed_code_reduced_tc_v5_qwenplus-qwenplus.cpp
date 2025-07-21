#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search helper to find the k-th smallest distance from b
ll query_kth_distance(ll a[], int n, ll b, int k) {
    // Create a copy of a[] to avoid modifying original array
    ll* sorted_a = new ll[n];
    copy(a, a + n, sorted_a);
    sort(sorted_a, sorted_a + n);

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (sorted_a[mid] < b)
            left = mid + 1;
        else
            right = mid - 1;
    }

    // Now 'left' is the insertion point for b in sorted array
    int l = left - 1, r = left;
    for (int i = 0; i < k; ++i) {
        if (l < 0)
            r++;
        else if (r >= n)
            l--;
        else if (abs(sorted_a[l] - b) <= abs(sorted_a[r] - b))
            l--;
        else
            r++;
    }
    
    ll res = max(abs(sorted_a[l + 1] - b), abs(sorted_a[r - 1] - b));
    delete[] sorted_a;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    
    sort(a, a + N);  // Sort A once
    
    // Precompute prefix sums for binary search usage
    // No need for prefix sums here as we can use two pointers approach

    for(int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Use two pointers approach to find k-th closest
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] < b)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        // 'left' is now the insertion point for b in the sorted array
        int l = left - 1, r = left;
        for (int i = 0; i < k - 1; ++i) {
            if (l < 0) r++;
            else if (r >= N) l--;
            else if (abs(a[l] - b) <= abs(a[r] - b)) l--;
            else r++;
        }
        
        // The k-th closest is either at l or r, whichever is appropriate
        ll result;
        if (l < 0) result = abs(a[r] - b);
        else if (r >= N) result = abs(a[l] - b);
        else result = min(abs(a[l] - b), abs(a[r] - b));
        
        cout << result << endl;
    }
    
    return 0;
}