#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 9;
vector<int> a;
vector<long long> dists;

int main() {
    int n, q;
    cin >> n >> q;
    a.reserve(n);
    long long x, k;
    
    for (int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }

    for (int i = 0; i < q; ++i) {
        cin >> x >> k;
        // Find the k-th closest point A_i to B_j = x
        sort(a.begin(), a.end());
        dists.clear();
        for (int ai : a) {
            dists.push_back(abs(ai - x));
        }
        sort(dists.begin(), dists.end());
        
        // Output the k-th smallest distance
        cout << dists[k - 1] << endl;
    }

    return 0;
}