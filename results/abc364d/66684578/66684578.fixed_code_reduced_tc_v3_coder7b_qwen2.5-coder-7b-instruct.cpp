#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

struct Point {
    int x, idx;
};

bool compare(Point a, Point b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<Point> pointsA(n);
    vector<int> kValues(q);
    
    for(int i = 0; i < n; ++i) {
        cin >> pointsA[i].x;
        pointsA[i].idx = i;
    }
    
    sort(pointsA.begin(), pointsA.end());
    
    for(int i = 0; i < q; ++i) {
        cin >> kValues[i];
    }
    
    for(int qi = 0; qi < q; ++qi) {
        int targetB, k;
        cin >> targetB >> k;
        
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(targetB - pointsA[mid].x <= pointsA[mid].x - targetB) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        int rank = lo;
        if(k > rank + 1 && rank < n - 1 && pointsA[rank].x == pointsA[rank + 1].x) {
            rank += 1;
        }
        
        cout << abs(pointsA[rank].x - targetB) << '\n';
    }
    
    return 0;
}