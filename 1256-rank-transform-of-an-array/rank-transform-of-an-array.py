class Solution:
    def arrayRankTransform(self, arr):
        # Step 1: sort unique elements
        sorted_unique = sorted(set(arr))
        
        # Step 2: assign ranks
        rank_map = {num: i+1 for i, num in enumerate(sorted_unique)}
        
        # Step 3: build result
        return [rank_map[num] for num in arr]
