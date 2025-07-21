#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N, Q;
vector<int> A, B;
vector<int> K;
vector<pair<int, int>> points;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    A.resize(N), B.resize(Q);
    K.resize(Q);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        points.push_back({A[i], i});
    }
    
    sort(points.begin(), points.end());
    
    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> K[i];
        points.push_back({B[i], -i});
    }
    
    sort(points.begin(), points.end(), cmp);
    
    int j = 0;
    vector<vector<int>> dists(Q);
    
    for (auto& [x, idx] : points) {
        if (idx >= 0) {
            dists[idx].push_back(x - A[idx]);
        } else {
            j++;
        }
    }
    
    for (int i = 0; i < Q; ++i) {
        sort(dists[i].begin(), dists[i].end());
        cout << dists[i][K[i] - 1] << '\n';
    }
    
    return 0;
}