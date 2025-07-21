#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

typedef long long ll;

// Function to compare pairs of integers
struct compare {
    bool operator()(pair<ll, ll> p1, pair<ll, ll> p2) {
        return p1.second > p2.second;
    }
};

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> A(N, 0);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> adj(N);
    for (ll i = 0; i < M; i++) {
        ll u, v, b;
        cin >> u >> v >> b;
        adj[u - 1].push_back(make_pair(v - 1, b)); // Adjusting for 0-based indexing
        adj[v - 1].push_back(make_pair(u - 1, b));
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compare> pq;

    // Initialize distances
    vector<ll> dist(N, INF);

    // Set distance of the source vertex to 0
    pq.push(make_pair(0, 0));
    dist[0] = A[0];

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        if (dist[u] < A[u]) continue;

        for (ll v : adj[u]) {
            ll alt = dist[u] + v.second + A[v.first];
            if (dist[v.first] > alt) {
                dist[v.first] = alt;
                pq.push(make_pair(alt, v.first));
            }
        }
    }

    // Output the minimum weight of the path to each vertex from 2 to N
    for (ll i = 1; i < N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}