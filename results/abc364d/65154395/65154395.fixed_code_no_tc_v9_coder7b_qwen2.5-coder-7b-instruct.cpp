#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll coord;
    int index;
};

bool cmp(const Point& p1, const Point& p2) {
    return p1.coord < p2.coord;
}

vector<ll> findKthClosestDistances(vector<Point>& pointsA, vector<int>& pointsB, vector<int>& kValues) {
    int n = pointsA.size();
    vector<ll> results(kValues.size());

    for (int j = 0; j < kValues.size(); ++j) {
        int k = kValues[j];
        vector<ll> distances(n);

        for (int i = 0; i < n; ++i) {
            distances[i] = abs(pointsA[i].coord - pointsB[j]);
        }

        sort(distances.begin(), distances.end());
        results[j] = distances[k - 1]; // Adjusting for zero-based indexing
    }

    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<Point> pointsA(n);
    for (int i = 0; i < n; ++i) {
        cin >> pointsA[i].coord;
        pointsA[i].index = i;
    }

    vector<int> pointsB(q), kValues(q);
    for (int i = 0; i < q; ++i) {
        cin >> pointsB[i] >> kValues[i];
    }

    vector<ll> results = findKthClosestDistances(pointsA, pointsB, kValues);

    for (ll result : results) {
        cout << result << '\n';
    }

    return 0;
}