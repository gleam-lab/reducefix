#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;
        vector<long long> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(a[i] - b);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}