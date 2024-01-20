#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> helper(int n) {
        if (n == 1) {
            return {"0", "1"};
        }

        vector<string> upperLevel = helper(n - 1);
        vector<string> myResu;

        for (int i = 0; i < upperLevel.size(); i++) {
            string rVal = upperLevel[i];
            myResu.push_back("0" + rVal);
        }

        for (int i = upperLevel.size() - 1; i >= 0; i--) {
            string rVal = upperLevel[i];
            myResu.push_back("1" + rVal);
        }

        return myResu;
    }

    vector<int> grayCode(int n) {
        vector<string> binaryStrings = helper(n);
        vector<int> result;

        for (const string &binaryStr : binaryStrings) {
            int decimalValue = 0;
            for (char digit : binaryStr) {
                decimalValue = decimalValue * 2 + (digit - '0');
            }
            result.push_back(decimalValue);
        }

        return result;
    }
};
