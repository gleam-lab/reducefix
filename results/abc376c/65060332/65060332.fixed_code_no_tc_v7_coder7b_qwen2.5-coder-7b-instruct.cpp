#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1), b(n);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];
    
    sort(a.begin() + 1, a.end());
    sort(b.begin(), b.end());

    // Initialize with the first box size
    pq.push(b[0]);

    int j = 0;
    for(int i = 1; i <= n; ++i) {
        while(!pq.empty() && pq.top() < a[i]) {
            pq.pop();
        }
        if(pq.empty()) { // No suitable box found
            cout << -1 << endl;
            return 0;
        }
        if(j < n - 1 && b[j + 1] > a[i]) { // New box needed
            pq.push(b[++j]);
        }
        pq.pop(); // Assign toy to the selected box
    }

    cout << pq.top() << endl; // Minimum box size used

    return 0;
}