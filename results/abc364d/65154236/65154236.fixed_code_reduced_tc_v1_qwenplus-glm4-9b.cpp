#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> b(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> distances(N, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            distances[j] = abs(a[i] - b[j]);
        }
        sort(distances.begin(), distances.end());
        for (int j = 0; j < q; ++j) {
            printf("%d\n", distances[j]);
        }
    }
    
    return 0;
}