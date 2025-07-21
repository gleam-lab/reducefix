#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search to find the k-th smallest distance from b to elements in a
int find_kth_distance(const vector<int>& a, long long b, int k) {
    int n = a.size();
    int left = 0;
    int right = max(abs((long long)a[0] - b), abs((long long)a.back() - b));

    while (left < right) {
        int mid = (left + right) / 2;
        // Two pointers for sliding window count
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && abs((long long)a[j] - b) <= mid) {
                ++j;
            }
            cnt += min(j, i + 1) - i;
            if (cnt >= k) break;
        }

        if (cnt >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < Q; ++i) {
        long long b;
        int k;
        cin >> b >> k;
        cout << find_kth_distance(a, b, k) << "\n";
    }

    return 0;
}