class Solution {
public:

    void printAllCombinations(string digits, unordered_map<char, string> mapping, int length, string ans, int index, vector<string>& returning) {

        if (index == length) {
            returning.push_back(ans);
            return;
        }

        char ch = digits[index];
        int size = mapping[ch].size();

        for (int i = 0; i < size; i++) {
            char character = mapping[ch][i];
            printAllCombinations(digits, mapping, length, ans + character, index + 1, returning);
        }
    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> mapping;
        int length = digits.length();
        vector<string> ans;

        if (length == 0) {
            return ans;
        }

        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        printAllCombinations(digits, mapping, length, "", 0, ans);

        return ans;
    }
};
