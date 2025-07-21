#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;

struct Element {
    int val, idx;
};

bool cmp(Element &a, Element &b) {
    return a.val > b.val;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        
        vector<Element> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].val; a[i].idx = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].val;
        }

        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());

        int res = INF;
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            pq.push(b[i].val);
            sum += b[i].val;
            if (pq.size() > k) {
                sum -= pq.top(); pq.pop();
            }
            if (i >= k - 1) {
                res = min(res, sum * a[i + 1].val);
            }
        }

        cout << res << '\n';
    }

    return 0;
}