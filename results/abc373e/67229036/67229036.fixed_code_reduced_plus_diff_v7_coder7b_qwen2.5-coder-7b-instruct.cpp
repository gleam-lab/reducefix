#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Candidate {
    ll votes, rank;
};

bool cmp(Candidate a, Candidate b) {
    return a.votes > b.votes;
}

vector<ll> minVotesToWin(vector<Candidate>& candidates, int M, ll totalVotes) {
    int n = candidates.size();
    vector<ll> result(n);

    sort(candidates.begin(), candidates.end(), cmp);

    for(int i = 0; i < n; ++i) {
        ll requiredVotes = 0;
        if(i + 1 <= M) {
            requiredVotes = (candidates[i].votes + 1) * (M - i) - totalVotes;
        }
        if(requiredVotes > 0) {
            result[candidates[i].rank] = requiredVotes;
        } else {
            result[candidates[i].rank] = 0;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    for(int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].rank = i;
    }
    
    vector<ll> results = minVotesToWin(candidates, M, K);
    
    for(ll res : results) {
        cout << res << " ";
    }
    
    return 0;
}