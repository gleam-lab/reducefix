#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> A, B;
vector<pair<ll, int>> dists;

void preprocess() {
    int n = A.size(), q = B.size();
    dists.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            dists.push_back({abs(A[i] - B[j]), j});
        }
    }
    sort(dists.begin(), dists.end());
}

void solve(int q) {
    preprocess();
    for (int i = 0; i < q; ++i) {
        int k = dists[i].first;
        int idx = dists[i].second;
        cout << k << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    A.resize(n), B.resize(q);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> B[i];
    }
    
    solve(q);
    
    return 0;
}