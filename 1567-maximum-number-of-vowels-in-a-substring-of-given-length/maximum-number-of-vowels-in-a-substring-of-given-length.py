class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = ['a', 'e', 'i', 'o', 'u']
        max_vowels = 0
        substr = []

        for i in range(0,k):
            substr.append(s[i])
            if s[i] in vowels:
                max_vowels += 1
        
        curr_vowels = max_vowels
        for j in range(k,len(s)):
            if substr[0] in vowels:
                curr_vowels -= 1
            
            substr.pop(0)
            if s[j] in vowels:
                curr_vowels += 1

            substr.append(s[j])
            if curr_vowels > max_vowels:
                max_vowels = curr_vowels

        return max_vowels
        