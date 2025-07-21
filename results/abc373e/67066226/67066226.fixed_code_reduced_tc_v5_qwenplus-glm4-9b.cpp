#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<pair<ll, int>> p(n);
    for(int i = 0; i < n; i++) {
        p[i] = {a[i], i};
    }
    sort(p.begin(), p.end(), greater<pair<ll, int>>());

    vector<ll> answers(n, -1);
    vector<ll> prefix(n);
    prefix[0] = a[p[0].second];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[p[i].second];
    }

    for(int i = 0; i < m; i++) {
        if(answers[p[i].second] != -1) continue;

        ll votes_needed = 0;
        ll votes_left = k;
        ll rank = i + 1;

        while(rank < n && votes_needed < votes_left && a[p[rank].second] == a[p[i].second]) {
            votes_needed += a[p[rank].second];
            rank++;
        }

        ll needed = votes_needed - a[p[i].second];
        ll competitor_votes = votes_left - votes_needed;
        ll competitors = n - i - 1;

        ll excess_votes = needed - competitors;
        if(excess_votes > 0) {
            answers[p[i].second] = votes_needed;
        } else {
            ll more_votes_needed = 0;
            ll remaining_competitors = competitors;
            for(int j = i + 1; j < n; j++) {
                if(a[p[j].second] > a[p[i].second]) {
                    remaining_competitors--;
                } else {
                    more_votes_needed = max(more_votes_needed, a[p[j].second] - a[p[i].second] - 1);
                }
            }

            if(remaining_competitors <= m) {
                ll votes_to_safe = m - remaining_competitors + more_votes_needed;
                if(votes_to_safe <= votes_left) {
                    answers[p[i].second] = votes_needed + votes_to_safe;
                }
            }
        }
    }

    for(ll &answer : answers) {
        if(answer == LLONG_MAX) {
            answer = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << answers[i] << (i < n - 1 ? " " : "");
    }
    cout << '\n';
}