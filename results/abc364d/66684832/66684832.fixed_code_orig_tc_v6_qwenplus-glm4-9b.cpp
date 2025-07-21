#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define int long long

int n, q;
vector<int> a;
vector<pair<int, int>> queries;

int kth_closest(int distance, int k) {
    int low = 0, high = 1e18;
    while (low < high) {
        int mid = (low + high + 1) >> 1;
        int count = 0;
        for (int x : a) {
            if (abs(x - distance) <= mid) {
                count++;
            }
        }
        if (count >= k) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    return low;
}

int main() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k);
    }
    for (auto &query : queries) {
        int distance = kth_closest(query.first, query.second);
        cout << distance << endl;
    }
    return 0;
}