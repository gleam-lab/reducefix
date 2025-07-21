#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> max_b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        max_b[i] = b[i];
    }
    
    int left = 0, right = *max_element(a.begin(), a.end());
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        vector<int> used(n - 1, false);
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            int best_box = n;
            for (int j = 0; j < n - 1; ++j) {
                if (!used[j] && a[i] <= max_b[j] && b[j] <= mid) {
                    best_box = min(best_box, b[j]);
                }
            }
            if (best_box == n) {
                possible = false;
                break;
            }
            for (int j = 0; j < n - 1; ++j) {
                if (used[j]) continue;
                if (b[j] == best_box) {
                    used[j] = true;
                    break;
                }
            }
        }
        if (possible) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();

    return 0;
}