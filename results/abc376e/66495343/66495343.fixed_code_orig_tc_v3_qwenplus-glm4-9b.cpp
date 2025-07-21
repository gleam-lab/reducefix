#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());

        int sum = 0;
        int max_val = 0;
        vector<int> indices;

        for (int i = 0; i < n && indices.size() < k; i++) {
            indices.push_back(i);
            sum += a[i].second;
            max_val = max(max_val, a[i].first);
        }

        int result = max_val * sum;

        for (int i = 0; i < n && indices.size() < k; i++) {
            int idx = indices.back();
            indices.pop_back();
            sum -= a[idx].second;

            int new_sum = sum + a[i].second;
            int new_max_val = max(max_val, a[i].first);

            if (new_sum * new_max_val < result) {
                result = new_sum * new_max_val;
                max_val = new_max_val;
                sum = new_sum;
                indices.push_back(i);
            }
        }

        cout << result << endl;
    }
    return 0;
}