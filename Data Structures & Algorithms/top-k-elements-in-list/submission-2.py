class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for x in nums:
            d.setdefault(x, 0)
            d[x] += 1
        return [key for key in sorted(d, key=lambda k: d.get(k), reverse=True)[:k]]
