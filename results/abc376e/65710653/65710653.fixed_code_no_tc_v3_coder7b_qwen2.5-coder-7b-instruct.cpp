#include <bits/stdc++.h>
using namespace std;

#define LL(...) ll __VA_ARGS__;scanf("%lld", &__VA_ARGS__)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define RREP(i, n) for(int i = (n)-1; i >= 0; --i)

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K;
        LL(N, K);
        
        vector<pair<int, int>> AB(N);
        REP(i, N) {
            LL(A, B);
            AB[i] = {A, B};
        }
        
        // Sort by A in descending order
        sort(AB.rbegin(), AB.rend());
        
        long long ans = LLONG_MAX;
        long long sum_B = 0;
        REP(i, K) {
            sum_B += AB[i].second;
        }
        ans = min(ans, (long long)AB[K-1].first * sum_B);
        
        RREP(i, N-K) {
            sum_B += AB[K+i].second - AB[i].second;
            ans = min(ans, (long long)AB[K+i].first * sum_B);
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}