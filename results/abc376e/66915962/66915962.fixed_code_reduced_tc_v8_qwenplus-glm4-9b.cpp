#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Pair each A[i] with B[i] and sort by A[i], the second element of the pair
        vector<pair<ll, ll>> AB(N);
        for (int i = 0; i < N; ++i) {
            AB[i] = {A[i], B[i]};
        }
        sort(AB.begin(), AB.end());

        // Calculate the minimum cost starting from the smallest A[i]
        ll min_cost = LLONG_MAX;
        ll sum_B = 0;
        for (int i = 0; i < N; ++i) {
            if (i >= K) {
                sum_B -= AB[i - K].second; // Remove the element that is leaving the window
            }
            sum_B += AB[i].second; // Add the new element that enters the window
            if (i >= K - 1) {
                min_cost = min(min_cost, AB[i].first * sum_B);
            }
        }

        cout << min_cost << '\n';
    }
}