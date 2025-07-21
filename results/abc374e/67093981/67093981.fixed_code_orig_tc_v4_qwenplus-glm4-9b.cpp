#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef struct { int a, p, b, q; } p;

int N, X;
vector<p> A;
long long dp[100][10000];

int min(int a, int b) { return a < b ? a : b; }

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b), rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)(A[i].p * A[i].b);
}

bool f(int n) {
    long long ct = 0;
    for (int i = 0; i < N; i++) {
        ct += cost(i, n);
        if (ct > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        p temp;
        iss >> temp.a >> temp.p >> temp.b >> temp.q;
        if (temp.a * temp.q < temp.b * temp.p) swap(temp.a, temp.b), swap(temp.p, temp.q);
        A.push_back(temp);
        dp[i][0] = 0;
        for (int j = 1; j <= temp.a * temp.b; j++) {
            dp[i][j] = min(dp[i][max(0, j - temp.a)] + temp.p, dp[i][max(0, j - temp.b)] + temp.q);
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }

    if (lo != hi && f(hi)) lo = hi;
    cout << lo << '\n';
}