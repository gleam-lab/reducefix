#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    int a = A[i].a, b = A[i].b;
    int p = A[i].p, q = A[i].q;
    long long full_cycles = n / (a * b);
    long long remainder = n % (a * b);
    return full_cycles * min(a * q, b * p) + dp[i][remainder];
}

bool f(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        A[i] = {a, p, b, q};
        for (int j = 0; j < a * b; ++j) {
            if (j == 0) {
                dp[i][j] = 0;
            } else {
                long long option1 = (j >= a) ? dp[i][j - a] + p : INT_MAX;
                long long option2 = (j >= b) ? dp[i][j - b] + q : INT_MAX;
                dp[i][j] = min(option1, option2);
            }
        }
    }

    int low = 0, high = 1e9;
    int answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (f(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", answer);

    return 0;
}