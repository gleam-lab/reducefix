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

int big = 1e9 + 7;

struct Point {
    int coord;
    int index;
};

bool compare(const Point &p1, const Point &p2) {
    return p1.coord < p2.coord;
}

int findKthClosest(vector<Point> &points, int target, int k) {
    sort(points.begin(), points.end(), compare);
    int n = points.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid > 0 && points[mid].coord - target < target - points[mid - 1].coord) {
            if (k <= mid)
                return points[mid - 1].index;
            else
                left = mid + 1;
        } else {
            if (k <= mid + 1)
                return points[mid].index;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<Point> pointsA(n);
    for (int i = 0; i < n; ++i) {
        cin >> pointsA[i].coord;
        pointsA[i].index = i;
    }
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    sort(pointsA.begin(), pointsA.end());
    
    for (auto &query : queries) {
        int target = query.first;
        int k = query.second;
        
        int resultIndex = findKthClosest(pointsA, target, k);
        cout << abs(target - pointsA[resultIndex].coord) << '\n';
    }
    
    return 0;
}