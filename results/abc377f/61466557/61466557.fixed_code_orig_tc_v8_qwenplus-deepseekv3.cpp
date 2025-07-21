#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, d1, d2; // d1: i-j, d2: i+j
    
    for (auto &q : queens) {
        cin >> q.first >> q.second;
        rows.insert(q.first);
        cols.insert(q.second);
        d1.insert(q.first - q.second);
        d2.insert(q.first + q.second);
    }
    
    ll attacked = 0;
    
    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked -= rows.size() * cols.size(); // subtract intersections
    
    // Diagonals (i - j = d)
    for (auto &d : d1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
        
        // Subtract intersections with rows and columns
        for (auto &r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
        for (auto &c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
        // Add back intersections of row and column on the diagonal
        for (auto &r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N && cols.count(c)) {
                attacked++;
            }
        }
    }
    
    // Anti-diagonals (i + j = d)
    for (auto &d : d2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
        
        // Subtract intersections with rows and columns
        for (auto &r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
        for (auto &c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
        // Add back intersections of row and column on the anti-diagonal
        for (auto &r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N && cols.count(c)) {
                attacked++;
            }
        }
    }
    
    // Subtract intersections between diagonals and anti-diagonals
    set<pair<ll, ll>> intersections;
    for (auto &diag : d1) {
        for (auto &anti_diag : d2) {
            ll r = (diag + anti_diag) / 2;
            ll c = (anti_diag - diag) / 2;
            if ((diag + anti_diag) % 2 == 0 && (anti_diag - diag) % 2 == 0) {
                if (1 <= r && r <= N && 1 <= c && c <= N) {
                    intersections.insert({r, c});
                }
            }
        }
    }
    attacked -= intersections.size();
    
    // Add back the intersections that are already captured by rows or columns
    for (auto &p : intersections) {
        if (rows.count(p.first) || cols.count(p.second)) {
            attacked++;
        }
    }
    
    // The answer is total squares minus attacked squares minus the existing queens (since they are already occupied)
    ll total = N * N;
    ll answer = total - attacked - M;
    
    cout << answer << endl;
    
    return 0;
}