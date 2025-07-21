#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;
long long n, k, ans;

struct Node {
    int val, idx;
    bool operator<(const Node &other) const {
        return val > other.val || (val == other.val && idx < other.idx);
    }
};

vector<Node> a, b;

void solve() {
    a.clear(), b.clear();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.emplace_back(x, i);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.emplace_back(x, i);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        pq.push(b[i].val);
        sum += b[i].val;
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k) {
            ans = min(ans, static_cast<long long>(a[i].val) * sum);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}