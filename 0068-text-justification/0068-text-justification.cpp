class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();

            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            int totalChars = 0;
            for (int k = i; k < j; k++) {
                totalChars += words[k].length();
            }

            int totalSpaces = maxWidth - totalChars;
            string line = "";

            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                int spacesBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = spacesBetween + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};