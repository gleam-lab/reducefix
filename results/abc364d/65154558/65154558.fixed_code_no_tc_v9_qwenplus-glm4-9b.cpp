#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int b, k;
        cin >> b >> k;
        int distance = 0;
        for (int i = 0; i < n; ++i) {
            distance = abs(a[i] - b);
            if (++k == distance) {
                cout << distance << endl;
                break;
            }
        }
    }

    return 0;
}