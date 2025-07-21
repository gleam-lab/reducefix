#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Candidate {
    ll votes, index;
};

bool compare(Candidate &a, Candidate &b) {
    return a.votes > b.votes;
}

vector<ll> minVotes(vector<Candidate> &candidates, int m, ll totalVotes) {
    sort(candidates.begin(), candidates.end(), compare);
    vector<ll> results(candidates.size());
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    
    for(int i = 0; i < m; ++i) {
        pq.push({candidates[i].votes, candidates[i].index});
        totalVotes -= candidates[i].votes;
    }
    
    for(int i = m; i < candidates.size(); ++i) {
        while(!pq.empty() && pq.top().first <= candidates[i].votes) {
            auto [topVotes, topIndex] = pq.top();
            pq.pop();
            
            if(totalVotes == 0 || pq.empty()) {
                results[topIndex] = candidates[i].votes - topVotes + 1;
                break;
            }
            
            totalVotes -= topVotes;
            pq.push({topVotes, topIndex});
        }
        
        if(pq.empty())
            break;
        
        pq.push({candidates[i].votes, candidates[i].index});
        totalVotes -= candidates[i].votes;
    }
    
    for(int i = m; i < candidates.size(); ++i) {
        if(results[candidates[i].index] != 0)
            continue;
        
        while(!pq.empty()) {
            auto [topVotes, topIndex] = pq.top();
            pq.pop();
            
            if(totalVotes == 0 || pq.empty()) {
                results[topIndex] = candidates[i].votes - topVotes + 1;
                break;
            }
            
            totalVotes -= top Votes;
            pq.push({topVotes, topIndex});
        }
        
        if(pq.empty())
            results[candidates[i].index] = -1;
    }
    
    return results;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; ll k;
    cin >> n >> m >> k;
    
    vector<Candidate> candidates(n);
    for(int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    vector<ll> results = minVotes(candidates, m, k);
    
    for(auto result : results)
        cout << result << " ";
    
    return 0;
}