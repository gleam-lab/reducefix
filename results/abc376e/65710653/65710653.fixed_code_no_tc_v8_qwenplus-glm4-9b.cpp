#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    while (cin >> n >> k) {
        vector<long long> p(n), q(n);
        for (long long i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (long long i = 0; i < n; i++) {
            cin >> q[i];
        }
        
        // Pairing p and q values and sort them based on the product A_i * B_i
        vector<pair<long long, long long>> a(n);
        for (long long i = 0; i < n; i++) {
            a[i] = {p[i] * q[i], q[i]};
        }
        sort(a.begin(), a.end()); // Sort by descending order of A_i * B_i
        set<long long> b(n - k + 1);
        
        // Calculate the sum of the first k elements starting from the highest product
        long long ans = a[0].first * a[0].second;
        long long sum = a[0].second;
        b.insert(a[0].second);
        
        // Iterate over the rest of the elements
        for (long long i = 1; i < n; i++) {
            sum += a[i].second;
            b.insert(a[i].second);
            
            // Remove the smallest element from the sum if we have more than k elements
            if (b.size() > k) {
                sum -= *b.begin();
                b.erase(b.begin());
            }
            
            // Calculate the answer for the current set of k elements
            long long currentAnswer = a[i].first * sum;
            ans = min(ans, currentAnswer);
        }
        cout << ans << endl;
    }
    return 0;
}