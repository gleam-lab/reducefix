#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    scanf("%lld %lld", &N, &M);
    
    set<ll> rows, cols, diags1, diags2;
    set<pair<ll, ll>> pieces;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a + b);
        diags2.insert(a - b);
        pieces.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();
    
    // Diagonals (i + j)
    for (auto d : diags1) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }
    
    // Anti-diagonals (i - j)
    for (auto d : diags2) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    
    // Subtract intersections between diags1 and diags2
    // Each piece (a, b) is at the intersection of a+b and a-b
    // So we have to subtract the count of pieces since they are counted in both diags
    unsafe -= pieces.size();
    
    // Total safe squares
    ll total = N * N;
    ll safe = total - unsafe;
    
    printf("%lld\n", safe);
    
    return 0;
}