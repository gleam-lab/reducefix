#include<bits/stdc++.h>

using namespace std;

struct Point{
    int val;
    int id;
};

bool cmp(Point a, Point b){
    return a.val < b.val;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<Point> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].val;
        A[i].id = i;
    }
    sort(A.begin(), A.end(), cmp);

    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        int idx = upper_bound(A.begin(), A.end(), (Point){b, INT_MAX}) - A.begin();
        ans[i] = abs(A[(idx+k-1)%n].val - b);
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}