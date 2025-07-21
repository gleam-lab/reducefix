#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Printer;
Printer A[100];
long long dp[100][10000];

int N, X;

// Calculate the minimum cost to print 'n' pages for printer 'i'
long long cost(int i, int n) {
    if (n == 0) return 0;
    long long cycle = n / (A[i].a * A[i].b);
    long long remainder = n % (A[i].a * A[i].b);
    return cycle * A[i].p * A[i].b + dp[i][remainder];
}

// Check if we can print 'n' pages within budget X
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        
        // Ensure a*q >= b*p (better to use a first)
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        
        A[i] = {a, p, b, q};
        
        // Precompute dp for this printer up to a*b pages
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = LLONG_MAX;
            if (j >= a) dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b) dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum pages possible
    int low = 0, high = 1;
    // Find upper bound
    while (isPossible(high)) {
        low = high;
        high = min(high * 2, INT_MAX - 1); // Prevent overflow
    }
    
    // Binary search between low and high
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (isPossible(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << low << endl;
    return 0;
}