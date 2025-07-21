#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<ll, int>> distances(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> distances[i].first; // Read the coordinate of A_i
        distances[i].second = i + 1; // Store the index (1-based)
    }

    for (int i = 0; i < Q; ++i) {
        int B, k;
        cin >> B >> k;

        // Create a vector of distances from each A_i to B
        vector<pair<ll, int>> db(N);
        for (int j = 0; j < N; ++j) {
            db[j] = {abs(distances[j].first - B), distances[j].second};
        }

        // Sort by distance
        sort(db.begin(), db.end());

        // Output the k-th closest distance
        cout << db[k - 1].second << endl;
    }

    return 0;
}