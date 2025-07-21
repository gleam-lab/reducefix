#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long coord;
    int index;
};

bool operator<(const Point& p1, const Point& p2) {
    return abs(p1.coord) < abs(p2.coord);
}

vector<long long> findKthClosestDistances(int N, int Q, vector<int>& a, vector<pair<int, int>>& queries) {
    vector<long long> results(Q);

    for (int i = 0; i < Q; ++i) {
        int b = queries[i].first;
        int k = queries[i].second;

        priority_queue<Point> pq;

        for (int j = 0; j < N; ++j) {
            long long dist = abs(a[j] - b);
            pq.push({dist, j});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        if (!pq.empty()) {
            results[i] = pq.top().coord;
        } else {
            results[i] = 0; // In case no valid point was found
        }
    }

    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<long long> results = findKthClosestDistances(N, Q, a, queries);

    for (long long result : results) {
        cout << result << '\n';
    }

    return 0;
}