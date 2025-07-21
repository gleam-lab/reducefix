#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10000];

int N;
long long X;

long long cost(int i, long long n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(long long n) {
    long long total_cost = 0;
    for(int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if(total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &N, &X);

    for(int i = 0; i < N; i++) {
        int a, p_val, b, q_val;
        scanf("%d %d %d %d", &a, &p_val, &b, &q_val);
        if(a * q_val < b * p_val) {
            swap(a, b);
            swap(p_val, q_val);
        }
        A[i] = {a, p_val, b, q_val};
        
        dp[i][0] = 0;
        for(int j = 1; j < a * b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p_val : p_val;
            long long option2 = (j >= b) ? dp[i][j - b] + q_val : q_val;
            dp[i][j] = min(option1, option2);
        }
    }

    long long lo = 0, hi = 1e18;
    while(lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if(f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", lo);
    return 0;
}