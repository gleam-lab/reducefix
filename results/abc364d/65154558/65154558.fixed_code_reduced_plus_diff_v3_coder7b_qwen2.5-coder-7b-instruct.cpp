#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const int N = 1e5 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

struct Point {
    ll x, idx;
};

vector<Point> pointsA, pointsB;
vector<ll> distances;

bool comparePoints(const Point& a, const Point& b) {
    return a.x < b.x;
}

ll binarySearch(ll target, ll start, ll end) {
    ll left = start, right = end;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (distances[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pointsA.push_back({x, i});
    }
    for(int i = 1; i <= q; i++) {
        int x, k; cin >> x >> k;
        pointsB.push_back({x, i});
    }
    
    sort(pointsA.begin(), pointsA.end(), comparePoints);
    sort(pointsB.begin(), pointsB.end(), comparePoints);

    distances.resize(n * q);
    int index = 0;
    for(int i = 0; i < q; i++) {
        for(int j = 0; j < n; j++) {
            distances[index++] = abs(pointsA[j].x - pointsB[i].x);
        }
    }

    sort(distances.begin(), distances.end());

    for(int i = 0; i < q; i++) {
        int k = pointsB[i].idx - 1;
        int result = distances[k];
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}