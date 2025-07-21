#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;

vector<ll> points;
ll n, q;

// Function to calculate the k-th nearest point to a given point
ll kthNearest(ll target, int k) {
    vector<ll> distances(points.size());
    for (int i = 0; i < points.size(); ++i) {
        distances[i] = abs(target - points[i]);
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    for (int i = 0; i < q; ++i) {
        ll x; int k;
        cin >> x >> k;
        cout << kthNearest(x, k) << '\n';
    }

    return 0;
}