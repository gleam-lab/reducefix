#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

int n, Q;
vector<int> a;
vector<pair<int, int>> queries;

int getDistance(int b, int k) {
    int left = -1e9, right = 1e9;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (int x : a) {
            if (abs(x - b) <= mid) {
                count++;
            }
        }
        if (count >= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return abs(left - b);
}

int main() {
    cin >> n >> Q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k);
    }
    
    sort(queries.begin(), queries.end());
    for (auto& q : queries) {
        cout << getDistance(q.first, q.second) << endl;
    }
    
    return 0;
}