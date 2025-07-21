#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 9;
int n, q;
vector<int> a(N);

struct Query {
    int b, k, idx;
    bool operator>(const Query& other) const {
        return b > other.b;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].b >> queries[i].k;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> results(q);
    for (int i = 0; i < q; ++i) {
        int b = queries[i].b;
        int k = queries[i].k;
        int left = -1, right = n;

        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            int diff = abs(a[mid] - b);
            if (mid == 0) {
                left = mid;
                break;
            } else if (diff == abs(a[mid - 1] - b)) {
                left = mid;
                break;
            } else if (diff < abs(a[mid - 1] - b)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        int dist = abs(a[left] - b);
        results[queries[i].idx] = dist;
    }

    for (int i = 0; i < q; ++i) {
        cout << results[i] << '\n';
    }

    return 0;
}