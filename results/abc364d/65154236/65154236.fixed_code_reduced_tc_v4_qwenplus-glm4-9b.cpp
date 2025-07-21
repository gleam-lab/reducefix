#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    for (long long i = 0; i < q; ++i) {
        long long b, k;
        cin >> b >> k;
        // Calculate the absolute distance between A_k closest to B_j and B_j
        long long distance = abs(a[k] - b);
        cout << distance << endl;
    }
    return 0;
}