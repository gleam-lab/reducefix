#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> A[MAXN], B[MAXN];

int binary_search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) {
            left = mid + 1;
            result = mid;
        } else right = mid - 1;
    }
    return result;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    // Collect distances
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        A[a].push_back(i);
    }
    
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        B[b].push_back(k - 1);  // Convert to zero-based index
    }

    // Process each query
    for (auto& [distances, queries] : B) {
        sort(distances.begin(), distances.end());
        for (int query : queries) {
            cout << distances[query] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}