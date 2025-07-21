#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int b, k;
        cin >> b >> k;

        priority_queue<pii, vector<pii>, greater<pii>> min_heap;

        for (int ai : a) {
            int dist = abs(ai - b);
            min_heap.push({dist, ai});
        }

        for (int i = 1; i < k; ++i) {
            min_heap.pop();
        }

        cout << min_heap.top().first << '\n';
    }

    return 0;
}