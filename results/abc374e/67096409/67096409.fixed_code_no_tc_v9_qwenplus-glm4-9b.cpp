#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{int a, p, b, q;} p;
p A[100];
long long dp[100][10000];

int N, X;
long long cost(int i, int n){
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)(A[i].p * A[i].b);
}

bool f(int n){
    long long ct = 0;
    for(int i = 0; i < N; i++){
        ct += cost(i, n);
        if(ct > X) return false;
    }
    return true;
}

int main(){
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++){
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        A[i] = {a, p, b, q};
    }

    // Initialize dp table
    for(int i = 0; i < N; i++){
        dp[i][0] = 0;
        for(int j = 1; j < A[i].a * A[i].b; j++){
            dp[i][j] = min(dp[i][max(0, j - A[i].a)] + A[i].p, dp[i][max(0, j - A[i].b)] + A[i].q);
        }
    }

    // Binary search to find the maximum value of n
    int lo = 0, hi = 1e9;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid - 1;
    }

    // Check if the minimum possible n+1 works
    if(lo != hi && f(lo + 1)) lo++;
    printf("%d\n", lo);
}