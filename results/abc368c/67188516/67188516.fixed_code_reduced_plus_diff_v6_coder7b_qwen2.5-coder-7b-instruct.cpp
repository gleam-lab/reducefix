#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<int>& h) {
    int n = h.size();
    vector<pair<int, int>> q(n);
    for (int i = 0; i < n; i++) {
        q[i] = {h[i], i};
    }
    sort(q.begin(), q.end());
    long long res = 0, t = 0;
    for (auto& [h, i]: q) {
        while (!h) break;
        int c = min(h, (t + 2) / 3 * 3);
        t += c;
        h -= c;
        res += c;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    cout << solve(h) << '\n';
    return 0;
}