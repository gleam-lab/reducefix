#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int a[N], b[N], sa[N];

int main() {
    int T, n, k;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &n, &k);
        long long sum = 0, ans = LLONG_MAX;

        // Initialize the sum of the largest elements in the first window of size k
        for (int i = 0; i < k; ++i) {
            scanf("%d", &a[i]);
            sum += b[i];
        }
        // Calculate the initial answer with the first window
        ans = min(ans, a[0] * sum);

        // Process the remaining elements
        for (int i = k; i < n; ++i) {
            scanf("%d", &a[i]);
            // Remove the element that is leaving the window and add the new element
            sum -= b[i - k];
            sum += b[i];
            // Calculate the answer for the current window
            ans = min(ans, max(a[i - k], a[i]) * sum);
        }

        // Output the minimum answer for this test case
        printf("%lld\n", ans);
    }

    return 0;
}