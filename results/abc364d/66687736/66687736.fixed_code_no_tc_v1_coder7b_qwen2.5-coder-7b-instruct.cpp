#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

const int big = 1e9 + 7;

struct Point {
    int x;
    int idx;
};

bool cmp(const Point& a, const Point& b) {
    return abs(a.x) < abs(b.x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vi distances(n);

    rep(i, n) {
        cin >> distances[i];
    }

    rep(j, q) {
        int b, k;
        cin >> b >> k;
        
        // Create a list of points with their absolute differences from b
        vi points;
        rep(i, n) {
            points.push_back({abs(distances[i] - b), i});
        }
        
        // Sort points based on the absolute difference
        sort(points.begin(), points.end(), cmp);
        
        // Get the k-th smallest difference
        int result = distances[points[k - 1].idx];
        
        // Print the result
        cout << abs(result - b) << '\n';
    }

    return 0;
}