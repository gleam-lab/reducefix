#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> items(n, vector<int>(4));
    for (int i = 0; i < n; ++i) {
        cin >> items[i][0] >> items[i][1] >> items[i][2] >> items[i][3];
    }

    int l = 0, r = 1e9 + 5;
    while (l <= r) {
        int mid = (l + r) / 2;
        long long sum = 0;
        for (const auto& item : items) {
            int a = item[0], p = item[1], b = item[2], q = item[3];
            int min_cost = INT_MAX;
            for (int j = 0; j <= b; ++j) {
                int cost = j * p;
                if ((mid - j * a) > 0) {
                    cost += ((mid - j * a) / b) * q;
                    if (((mid - j * a) % b) != 0) ++cost;
                }
                min_cost = min(min_cost, cost);
            }
            for (int j = 0; j <= a; ++j) {
                int cost = j * q;
                if ((mid - j * b) > 0) {
                    cost += ((mid - j * b) / a) * p;
                    if (((mid - j * b) % a) != 0) ++cost;
                }
                min_cost = min(min_cost, cost);
            }
            sum += min_cost;
        }
        if (sum <= x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}