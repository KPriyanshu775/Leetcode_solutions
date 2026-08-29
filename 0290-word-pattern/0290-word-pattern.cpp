class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (char2word.count(c) && char2word[c] != w) {
                return false;
            }
            if (word2char.count(w) && word2char[w] != c) {
                return false;
            }
            
            char2word[c] = w;
            word2char[w] = c;
        }
        
        return true;
    }
};