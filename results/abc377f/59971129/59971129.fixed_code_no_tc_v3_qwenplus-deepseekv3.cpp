#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    scanf("%lld %lld", &N, &M);
    
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N - M;
    ll dangerous = 0;
    
    dangerous += rows.size() * N;
    dangerous += cols.size() * N;
    dangerous -= rows.size() * cols.size();
    
    for (auto d : diag1) {
        ll min_ab = max(1LL - d, 1LL);
        ll max_ab = min(N - d, N);
        if (min_ab > max_ab) continue;
        dangerous += (max_ab - min_ab + 1);
    }
    
    for (auto d : diag2) {
        ll min_a = max(1LL, d - N);
        ll max_a = min(N, d - 1);
        if (min_a > max_a) continue;
        dangerous += (max_a - min_a + 1);
    }
    
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N && cols.find(b) != cols.end()) {
                dangerous--;
            }
        }
        for (auto d : diag2) {
            ll b = d - a;
            if (b >= 1 && b <= N && cols.find(b) != cols.end()) {
                dangerous--;
            }
        }
    }
    
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = b + d;
            if (a >= 1 && a <= N && rows.find(a) != rows.end()) {
                dangerous--;
            }
        }
        for (auto d : diag2) {
            ll a = d - b;
            if (a >= 1 && a <= N && rows.find(a) != rows.end()) {
                dangerous--;
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N && (d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (rows.find(a) != rows.end() || cols.find(b) != cols.end()) {
                    dangerous--;
                }
            }
        }
    }
    
    ll safe = total - dangerous;
    printf("%lld\n", safe);
    
    return 0;
}