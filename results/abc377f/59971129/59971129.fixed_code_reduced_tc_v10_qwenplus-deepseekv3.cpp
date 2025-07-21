#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    ll attacked = 0;
    
    // Subtract rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * (N - rows.size());
    
    // Subtract diagonals
    ll diag1_count = 0;
    for (auto d : diag1) {
        // Calculate the number of squares in the diagonal d = a - b
        ll lower = max(1LL, 1 - d);
        ll upper = min(N, N - d);
        if (upper >= lower)
            diag1_count += upper - lower + 1;
    }
    
    ll diag2_count = 0;
    for (auto d : diag2) {
        // Calculate the number of squares in the diagonal d = a + b
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        if (upper >= lower)
            diag2_count += upper - lower + 1;
    }
    
    attacked += diag1_count + diag2_count;
    
    // Add back intersections of rows and columns with diagonals
    // Intersection of rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N && cols.find(c) == cols.end())
                attacked--;
        }
    }
    
    // Intersection of rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N && cols.find(c) == cols.end())
                attacked--;
        }
    }
    
    // Intersection of columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N && rows.find(r) == rows.end())
                attacked--;
        }
    }
    
    // Intersection of columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N && rows.find(r) == rows.end())
                attacked--;
        }
    }
    
    // Add back squares that are in both diag1 and diag2 (if any)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                if (rows.find(r) == rows.end() && cols.find(c) == cols.end())
                    attacked++;
            }
        }
    }
    
    ll safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}