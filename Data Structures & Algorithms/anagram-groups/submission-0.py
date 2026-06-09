class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for s in strs:
            key = [0] * 26
            for ch in s:
                key[ord(ch) - ord("a")] += 1
            k = tuple(key)
            dic.setdefault(k, []).append(s)
        return list(dic.values())
