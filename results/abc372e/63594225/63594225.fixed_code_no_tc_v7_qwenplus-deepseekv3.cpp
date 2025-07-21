#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<priority_queue<int, vector<int>, greater<int>>> top_k; // Min-heap to keep top 10 largest
vector<int> p;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;

    // Ensure 'a' is the larger component
    if (top_k[a].size() < top_k[b].size()) {
        swap(a, b);
    }

    // Merge the top elements from 'b' into 'a'
    while (!top_k[b].empty()) {
        top_k[a].push(top_k[b].top());
        top_k[b].pop();
        if (top_k[a].size() > 10) {
            top_k[a].pop(); // Keep only the top 10
        }
    }

    p[b] = a;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n + 1);
    top_k.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        top_k[i].push(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            if (top_k[a].size() < b) {
                cout << -1 << '\n';
            } else {
                // Since we use a min-heap, the k-th largest is (size - k)-th element if sorted in ascending order.
                // To get the k-th largest, we need to collect all elements and then select.
                // To optimize, we can transfer the elements to a vector and sort.
                vector<int> temp;
                while (!top_k[a].empty()) {
                    temp.push_back(top_k[a].top());
                    top_k[a].pop();
                }
                sort(temp.rbegin(), temp.rend());
                cout << temp[b - 1] << '\n';
                // Restore the heap
                for (int num : temp) {
                    top_k[a].push(num);
                }
            }
        }
    }

    return 0;
}