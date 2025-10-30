import sys

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    A = list(map(int, data[2:2+n]))
    
    # We need to remove exactly K elements, leaving (n - k) elements.
    # We want to minimize (max(B) - min(B)) for the remaining subsequence B.
    # Since we can only remove elements and keep the rest in order,
    # the remaining elements form a contiguous subsequence? No — not necessarily.
    # But note: we are allowed to remove any K elements arbitrarily (not necessarily contiguous),
    # but the remaining elements must stay in original order.
    
    # However, to minimize the difference between max and min of the remaining,
    # it's optimal to remove some of the largest and/or smallest values.
    
    # Insight:
    # The final array B is formed by removing K elements. So we keep (n-K) elements.
    # Since we can choose which ones to remove, one strategy is:
    #   - Sort the array along with original indices.
    #   - Try all possible ways to remove some from left (smallest) and some from right (largest)
    #     such that total removed is K.
    #
    # Specifically:
    # Let’s say we decide to keep a contiguous block in the sorted array? 
    # But the kept elements must appear in original order — so we cannot reorder.
    #
    # Alternate approach:
    # Instead, consider that the best remaining sequence will have its minimum and maximum
    # among the values in A. To minimize (maxB - minB), we can try to fix the min and max
    # of the result.
    #
    # Better idea:
    # We can try all possible splits where we remove i elements from the left (smallest i)
    # and (K - i) elements from the right (largest K-i) in the sorted array.
    # But then we must check whether the remaining values can form a valid subsequence
    # in the original order? Actually, no — because if we take all values except the i smallest
    # and (K-i) largest, then any subset of these values appears in original order.
    # So we can always pick the remaining (n-K) values from the middle part.
    #
    # However, we don't need to preserve contiguity — just relative order.
    # And since we are keeping *all* values that are not among the i smallest or (K-i) largest,
    # then certainly we can form a sequence from them in original order.
    #
    # BUT: what if there are duplicates? Then we might remove too many or too few.
    #
    # Actually, correct method:
    # Sort the array by value, but keep track of indices.
    # For a fixed i in [0, K], let:
    #   Remove i smallest elements and (K - i) largest elements.
    #   Then the candidate answer is: (the largest remaining value) - (the smallest remaining value)
    # But wait: after removal, the actual min and max of the remaining set are known:
    #   If we sort A, then:
    #       sorted_A[0..i-1] are removed (i smallest)
    #       sorted_A[n-(K-i)..n-1] are removed (K-i largest)
    #       So the remaining values are from sorted_A[i : n-(K-i)]
    #   Then the min is sorted_A[i], max is sorted_A[n-(K-i)-1]
    #   So candidate = sorted_A[n-(K-i)-1] - sorted_A[i]
    #
    # But: can we actually keep all the values in the range [sorted_A[i], sorted_A[n-(K-i)-1]]?
    # Not necessarily — because we must preserve order and cannot break the sequence.
    # However, note: we are allowed to remove any K elements arbitrarily. So if we decide
    # to keep all values that are >= sorted_A[i] and <= sorted_A[n-(K-i)-1], we may keep more than (n-K) elements.
    # But we only need to keep (n-K) elements. So we can always choose a subsequence of (n-K) elements
    # from this range, as long as there are at least (n-K) elements in this range.
    #
    # But our removal strategy above removes exactly the i smallest and (K-i) largest.
    # So the number of remaining elements is n - K, and they are exactly those in positions
    # i to n-(K-i)-1 in sorted order. However, these elements exist in the original array,
    # and we can keep them in their original order — just skip the ones we decided to remove.
    #
    # Therefore, for each i in 0..K:
    #   candidate = sorted_A[n - (K - i) - 1] - sorted_A[i]
    # and we take the minimum candidate over i.
    #
    # Example: N=4, K=2, A=[1,3,2,4]
    #   sorted_A = [1,2,3,4]
    #   i=0: remove 0 smallest, 2 largest -> keep [1,2] -> max=2,min=1 -> diff=1
    #         but wait: we keep values <= 3-1? n-(K-i)=4-2=2 -> index 2-1=1 -> sorted_A[1]=2
    #         so max = sorted_A[1] = 2, min = sorted_A[0] = 1 -> diff=1
    #   i=1: remove 1 smallest, 1 largest -> keep [2,3] -> diff=1
    #   i=2: remove 2 smallest, 0 largest -> keep [3,4] -> diff=1
    #   So min diff = 1.
    #   But can we achieve 1? Yes.
    #
    # However, is this always valid? Yes, because we are allowed to remove any K elements.
    # So we can choose to remove the i smallest and (K-i) largest, and keep the rest.
    # The rest will have min = sorted_A[i], max = sorted_A[n - (K-i) - 1].
    #
    # But caution: what if the same value appears multiple times? Then we might remove one occurrence
    # of a small value and keep another. But in sorted_A, we include duplicates.
    # Our slicing takes care of that: we remove the first i elements (which are the i smallest, including duplicates)
    # and the last (K-i) elements (largest).
    #
    # Therefore, algorithm:
    #   sort A
    #   ans = infinity
    #   for i in range(0, K+1):
    #       j = n - (K - i)   # starting index of the removed large part
    #       current_max = sorted_A[j - 1]   # last element not removed from the right
    #       current_min = sorted_A[i]
    #       ans = min(ans, current_max - current_min)
    #
    #   print(ans)
    #
    # Let's test with sample: N=4, K=2, A=[1,3,2,4] -> sorted_A=[1,2,3,4]
    #   i=0: j = 4 - (2-0) = 2 -> current_max = sorted_A[1] = 2, current_min = sorted_A[0]=1 -> diff=1
    #   i=1: j = 4 - (2-1)=3 -> current_max = sorted_A[2]=3, current_min = sorted_A[1]=2 -> diff=1
    #   i=2: j = 4 - (2-2)=4 -> current_max = sorted_A[3]=4, current_min = sorted_A[2]=3 -> diff=1
    #   ans=1 -> correct.
    #
    # Another test: N=3, K=1, A=[1,5,3]
    #   sorted_A=[1,3,5]
    #   i=0: j=3-(1-0)=2 -> max=sorted_A[1]=3, min=sorted_A[0]=1 -> diff=2
    #   i=1: j=3-(1-1)=3 -> max=sorted_A[2]=5, min=sorted_A[1]=3 -> diff=2
    #   ans=2.
    #   Possibilities: remove 1 -> [5,3] -> max=5,min=3 -> diff=2
    #                 remove 5 -> [1,3] -> diff=2
    #                 remove 3 -> [1,5] -> diff=4
    #   So min=2 -> correct.
    #
    # But wait: what if we could get a better spread by not removing extreme values?
    # Example: Is there a case where removing a middle value gives a smaller range?
    #   Suppose A = [1, 10, 2, 11], K=2.
    #   Possibility: remove 1 and 11 -> keep [10,2] -> range = 8
    #                remove 1 and 10 -> keep [2,11] -> range = 9
    #                remove 1 and 2 -> keep [10,11] -> range = 1
    #                ... but wait: if we remove 1 and 2, we get [10,11] -> range=1.
    #   Now apply our method:
    #       sorted_A = [1,2,10,11], n=4, k=2
    #       i=0: remove 0 smallest, 2 largest -> keep [1,2] -> range=1
    #       i=1: remove 1 smallest, 1 largest -> keep [2,10] -> range=8
    #       i=2: remove 2 smallest, 0 largest -> keep [10,11] -> range=1
    #       min = 1 -> correct.
    #   So it works.
    #
    # However, note: when we remove the two smallest (1 and 2), we are allowed to do that.
    # And the remaining [10,11] is in order — yes.
    #
    # Therefore, the solution is to sort and try all i in [0,K].
    
    A.sort()
    ans = float('inf')
    
    for i in range(K + 1):
        # Remove i smallest and (K - i) largest
        # Remaining: from index i to n - (K - i) - 1
        j = n - (K - i)  # j is the start of the removed large part, so last kept is j-1
        if j - 1 < i:
            # This means we are trying to remove more than available
            # But since i <= K and K < n, and j = n - (K-i), then j-1 >= i ?
            # j-1 = n - (K-i) - 1
            # We require j-1 >= i  => n - (K-i) - 1 >= i  => n - K + i - 1 >= i => n-K-1 >= 0 => n>K, which holds.
            # So j-1 >= i always? Let's see: n-K-1 >= 0 -> true because K < n.
            # So j-1 - i + 1 = n-K >= 1 -> at least one element.
            pass
        current_range = A[j - 1] - A[i]
        if current_range < ans:
            ans = current_range
    
    print(ans)

if __name__ == "__main__":
    main()