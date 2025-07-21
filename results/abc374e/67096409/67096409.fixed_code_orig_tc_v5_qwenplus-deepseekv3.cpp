#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p_val, b, q_val;
        scanf("%d %d %d %d", &a, &p_val, &b, &q_val);
        if (a * q_val < b * p_val) {
            swap(a, b);
            swap(p_val, q_val);
        }
        A[i] = {a, p_val, b, q_val};
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p_val : p_val;
            long long option2 = (j >= b) ? dp[i][j - b] + q_val : q_val;
            dp[i][j] = min(option1, option2);
        }
    }

    int low = 0, high = 1e9;
    int answer = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
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