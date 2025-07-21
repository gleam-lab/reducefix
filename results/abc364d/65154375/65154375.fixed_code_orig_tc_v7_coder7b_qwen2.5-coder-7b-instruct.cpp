#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> A, B;
int N, Q;

struct Point {
    int id, dist;
};

bool compare(Point p1, Point p2) {
    return p1.dist < p2.dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    A.resize(N), B.resize(Q);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        cin >> B[i] >> A[i]; // Read both B_i and A_i for each query
        sort(A.begin(), A.end());
    }

    for(int i = 0; i < Q; i++) {
        vector<Point> points;
        for(int j = 0; j < N; j++) {
            points.push_back({j, abs(B[i] - A[j])});
        }
        sort(points.begin(), points.end(), compare);
        cout << points[k - 1].dist << endl;
    }

    return 0;
}