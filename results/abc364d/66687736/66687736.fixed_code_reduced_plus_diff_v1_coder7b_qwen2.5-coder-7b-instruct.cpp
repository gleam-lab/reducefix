#include <bits/stdc++.h>
using namespace std;

vector<int> points;
vector<int> queries;
vector<pair<int, int>> results;

void preprocess() {
    sort(points.begin(), points.end());
}

int binary_search(int target) {
    int left = 0, right = points.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (points[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void process_queries() {
    for (auto query : queries) {
        int index = binary_search(query);
        int dist = abs(points[index] - query);
        results.push_back({dist, index});
    }
}

void output_results() {
    for (auto result : results) {
        cout << result.first << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    points.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    queries.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    preprocess();
    process_queries();
    output_results();

    return 0;
}