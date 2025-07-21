#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> p[i].second;
        }
        sort(p, p + N);

        priority_queue<int> pq;
        long long sum = 0;
        for (int i = 0; i < K - 1; ++i) {
            sum += p[i].second;
            pq.push(p[i].second);
        }

        long long min_product = LLONG_MAX;
        for (int i = K - 1; i < N; ++i) {
            long long current_sum = sum + p[i].second;
            long long current_product = current_sum * p[i].first;
            if (current_product < min_product) {
                min_product = current_product;
            }

            if (!pq.empty() && pq.top() > p[i].second) {
                sum -= pq.top();
                pq.pop();
                sum += p[i].second;
                pq.push(p[i].second);
            }
        }
        cout << min_product << '\n';
    }
    return 0;
}