#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int solve(int n, int k, vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> c;
    for (int i = 0; i < n; ++i) {
        c.emplace_back(b[i], a[i]);
    }
    sort(c.begin(), c.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    priority_queue<int, vector<int>, greater<int>> q;
    long long sum = 0;
    int min_value = 2e18;
    
    for (int i = 0; i < n; ++i) {
        if (k > 0 && q.size() < k) {
            q.push(c[i].first);
            sum += c[i].first;
        } else if (q.size() >= k) {
            sum += c[i].first;
            sum -= q.top();
            q.pop();
        }
        
        if (q.size() == k) {
            min_value = min(min_value, c[i].second * sum);
        }
    }

    return min_value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        cout << solve(n, k, a, b) << endl;
    }

    return 0;
}