ll min_votes_needed(ll current_votes, ll remaining_votes) {
    ll votes_needed = 0;
    ll count_more = 0;
    for (ll votes : A) {
        if (votes > current_votes + remaining_votes) {
            count_more++;
            votes_needed += votes - current_votes - remaining_votes;
        }
    }
    return votes_needed > remaining_votes ? -1 : votes_needed;
}

for (ll i = 0; i < N; ++i) {
    ll current_votes = A[i];
    ll remaining_votes = K - prefix_sum[i]; // prefix_sum[i] is the sum of votes of top candidates before A[i]
    ll low = 0, high = remaining_votes + 1;
    
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        int needed = min_votes_needed(current_votes, mid);
        if (needed >= 0) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    
    ans[i] = low == remaining_votes + 1 ? -1 : low;
}