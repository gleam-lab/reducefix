#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

struct Element {
    int first, second;
};

bool compare(const Element &a, const Element &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

long long minProduct(int n, int k, vector<int>& A, vector<int>& B) {
    vector<Element> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {A[i], B[i]};
    }

    sort(pairs.begin(), pairs.end(), compare);

    long long sum = 0, result = LLONG_MAX;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; ++i) {
        sum += pairs[i].second;
        pq.push(pairs[i].second);
    }

    result = min(result, static_cast<long long>(pairs[k - 1].first) * sum);

    for (int i = k; i < n; ++i) {
        if (pq.top() < pairs[i].second) {
            sum -= pq.top();
            pq.pop();
            sum += pairs[i].second;
            pq.push(pairs[i].second);
        }
        result = min(result, static_cast<long long>(pairs[i].first) * sum);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];

        cout << minProduct(n, k, A, B) << '\n';
    }

    return 0;
}