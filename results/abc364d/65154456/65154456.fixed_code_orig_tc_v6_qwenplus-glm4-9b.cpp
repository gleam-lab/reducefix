#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N];
int cnt[N];

// Function to preprocess the points A and create the cumulative count array
void preprocess(int n) {
    for (int i = 1; i <= n; i++) {
        cnt[lower_bound(a + 1, a + n + 1, a[i]) - a]++; // Increment the count of points within the current distance
    }
    for (int i = 1; i <= n + 1; i++) {
        cnt[i] += cnt[i - 1]; // Convert the count array to cumulative count array
    }
}

// Function to check if there are at least k points within distance `mid`
bool check(int mid, int k) {
    return cnt[mid + 1] >= k;
}

// Function to find the k-th closest distance from B
int kthClosest(int x, int k) {
    int l = -1, r = 1e9;
    while (r - l > 1) { // Binary search
        int mid = (l + r) / 2;
        if (check(mid, k)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    preprocess(n); // Preprocess the points

    while (q--) {
        int x, k;
        cin >> x >> k;
        int ans = kthClosest(x, k);
        cout << ans << '\n';
    }

    return 0;
}