#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n+1);
    points[0] = {0, 0}; // Starting point at origin

    for(int i = 1; i <= n; ++i){
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    for(int i = 1; i <= n; ++i){
        int dx = points[i].first - points[i-1].first;
        int dy = points[i].second - points[i-1].second;
        total_cost += sqrt(dx*dx + dy*dy); // Corrected calculation of Euclidean distance
    }

    // Adding the cost to return to the origin
    int dx = points[n].first - points[0].first;
    int dy = points[n].second - points[0].second;
    total_cost += sqrt(dx*dx + dy*dy);

    cout << fixed << setprecision(8) << total_cost << '\n'; // Ensuring precision as required

    return 0;
}