class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        auto isVowel = [](char c) {
            char lower = std::tolower(c);
            return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
        };

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};