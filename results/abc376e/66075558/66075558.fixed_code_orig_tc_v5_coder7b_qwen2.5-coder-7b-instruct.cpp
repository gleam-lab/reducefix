#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Element {
    int valA, idxA, valB, idxB;
};

bool compare(const Element &a, const Element &b) {
    if (a.valA != b.valA) return a.valA > b.valA;
    return a.valB < b.valB;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            cin >> elements[i].valA;
            elements[i].idxA = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> elements[i].valB;
            elements[i].idxB = i;
        }

        // Sort elements based on the custom comparator
        sort(elements.begin(), elements.end(), compare);

        // Use a priority queue to keep track of the top K elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sumB = 0;
        for (int i = 0; i < n; ++i) {
            int valA = elements[i].valA, valB = elements[i].valB, idxA = elements[i].idxA, idxB = elements[i].idxB;
            if (pq.size() < k) {
                pq.push({valB, idxB});
                sumB += valB;
            } else if (valB < pq.top().first) {
                sumB -= pq.top().first;
                sumB += valB;
                pq.pop();
                pq.push({valB, idxB});
            }
        }

        // Calculate the result
        int result = pq.top().first * elements[k-1].valA;
        cout << result << "\n";
    }

    return 0;
}