#include <bits/stdc++.h>
using namespace std;

struct Element {
    int max_val, sum;
};

bool compare(Element &a, Element &b) {
    return a.max_val > b.max_val || (a.max_val == b.max_val && a.sum < b.sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            cin >> elements[i].max_val >> elements[i].sum;
        }

        sort(elements.begin(), elements.end(), compare);

        long long result = 0;
        priority_queue<int> pq;
        long long current_sum = 0;

        for (int i = 0; i < k; ++i) {
            pq.push(-elements[i].sum);
            current_sum += elements[i].sum;
        }

        result = static_cast<long long>(elements[k - 1].max_val) * current_sum;

        for (int i = k; i < n; ++i) {
            int removed = -pq.top(); pq.pop();
            int added = elements[i].sum;
            pq.push(-added);
            current_sum += added - removed;
            result = min(result, static_cast<long long>(elements[i].max_val) * current_sum);
        }

        cout << result << "\n";
    }

    return 0;
}