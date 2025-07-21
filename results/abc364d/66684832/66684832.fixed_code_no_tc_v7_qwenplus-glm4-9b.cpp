#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 200000;

vector<int> a(MAX_N + 1);
vector<pair<int, int>> queries;

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k - 1); // Store k-1 because k is 1-based index
    }

    // Sort the array `a` to prepare for the nearest point search
    sort(a.begin(), a.end());

    // Process each query
    for (auto& [b, k] : queries) {
        // Binary search to find the k-th closest point
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (a[mid] <= b + a[k]) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        // Calculate the minimum distance from the found point to b
        int min_distance = min(abs(b - a[low]), abs(b - a[low + 1]));
        cout << min_distance << endl;
    }

    return 0;
}