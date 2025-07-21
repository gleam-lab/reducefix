#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<long long> candidates;
    
    // Check the case where the new box is used for the largest toy in A
    {
        vector<long long> newB = B;
        newB.push_back(A.back());
        sort(newB.begin(), newB.end());
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] > newB[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            candidates.push_back(A.back());
        }
    }
    
    // Check the case where the new box is used for the largest toy in A not covered by existing B
    {
        int i = 0, j = 0;
        int count = 0;
        long long last_unmatched = -1;
        while (i < N && j < N-1) {
            if (A[i] <= B[j]) {
                ++i;
                ++j;
            } else {
                last_unmatched = A[i];
                ++i;
            }
        }
        if (i < N) {
            last_unmatched = A[i];
        }
        if (last_unmatched != -1) {
            candidates.push_back(last_unmatched);
        }
    }
    
    // Check all possible candidates
    long long min_x = LLONG_MAX;
    for (long long x : candidates) {
        vector<long long> newB = B;
        newB.push_back(x);
        sort(newB.begin(), newB.end());
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] > newB[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            min_x = min(min_x, x);
        }
    }
    
    if (min_x != LLONG_MAX) {
        cout << min_x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}