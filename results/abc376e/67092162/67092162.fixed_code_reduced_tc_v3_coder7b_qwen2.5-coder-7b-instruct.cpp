#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;

struct Element {
    ll a, b;
    bool operator<(const Element& other) const {
        return a * other.b > other.a * b;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            cin >> elements[i].a >> elements[i].b;
        }

        // Sort based on custom comparator
        sort(elements.begin(), elements.end());

        // Use a min-heap to keep track of the smallest sums
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += elements[i].b;
            pq.push(elements[i].b);
        }

        ll result = current_sum * elements[k - 1].a;

        for (int i = k; i < n; ++i) {
            if (elements[i].b < pq.top()) {
                current_sum -= pq.top();
                pq.pop();
                current_sum += elements[i].b;
                pq.push(elements[i].b);
            }
            result = min(result, current_sum * elements[i].a);
        }

        cout << result << '\n';
    }

    return 0;
}