# https://neetcode.io/problems/is-palindrome/question?list=neetcode150
class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while not isAlphaNum(s[l]):
                if s[l] == s[r]:
                    break
                l += 1
            while not isAlphaNum(s[r]):
                if s[l] == s[r]:
                    break
                r -= 1

            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True


def isAlphaNum(s):
    return (
        (ord("A") <= ord(s) <= ord("Z"))
        or ord("a") <= ord(s) <= ord("z")
        or ord("0") <= ord(s) <= ord("9")
    )
