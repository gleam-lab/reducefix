#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    set<long long> toy_sizes(A.begin(), A.end());

    // Calculate gcd of all toy sizes
    long long gcd_value = *toy_sizes.begin();
    for (int i = 1; i < toy_sizes.size(); i++) {
        gcd_value = gcd(gcd_value, *toy_sizes.begin() + i);
    }

    // Find the minimum box size that is a divisor of the gcd value
    for (int i = 2; i * i <= gcd_value; i++) {
        if (gcd_value % i == 0) {
            // Check if there's a box of this size
            if (find(B.begin(), B.end(), i) != B.end()) {
                cout << i << endl;
                return 0;
            }
            // Also check the corresponding divisor gcd_value / i
            if (find(B.begin(), B.end(), gcd_value / i) != B.end()) {
                cout << gcd_value / i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}