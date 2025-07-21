#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Point {
    int coord, idx;
};

bool cmp(const Point &a, const Point &b) {
    return a.coord < b.coord;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<Point> A(n), B(q);
    for(int i = 0; i < n; ++i) {
        cin >> A[i].coord;
        A[i].idx = i + 1;
    }
    
    for(int i = 0; i < q; ++i) {
        cin >> B[i].coord >> B[i].idx;
    }
    
    sort(A.begin(), A.end(), cmp);
    
    for(int i = 0; i < q; ++i) {
        int target_coord = B[i].coord;
        int k = B[i].idx;
        
        int low = 0, high = n - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            
            if((mid == 0 || abs(A[mid].coord - target_coord) <= abs(A[mid - 1].coord - target_coord)) && 
               (mid == n - 1 || abs(A[mid].coord - target_coord) <= abs(A[mid + 1].coord - target_coord))) {
                break;
            }
            
            if(mid > 0 && abs(A[mid].coord - target_coord) > abs(A[mid - 1].coord - target_coord)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        int result = abs(A[low].coord - target_coord);
        cout << result << '\n';
    }
    
    return 0;
}