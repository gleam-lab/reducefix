#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
vector<long long> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto distance = [](long long x, long long b) {
        return abs(x - b);
    };

    while (q--) {
        long long b;
        int k;
        cin >> b >> k;

        // Create a max-heap to keep track of the k smallest distances
        priority_queue<long long> max_heap;

        // Binary search bounds for distance
        long long low = 0;
        long long high = 2e8 + 10; // Sufficient upper bound

        while (low < high) {
            long long mid = (low + high) / 2;

            // Count how many points are within distance `mid` from b
            int left = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int right = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            int count = right - left;

            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }

    return 0;
}