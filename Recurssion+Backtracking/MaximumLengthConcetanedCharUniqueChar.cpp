#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

    
    void backtrack(vector<string>& arr, int index, string current, int& result) {
        unordered_set<char> uniqueChars(current.begin(), current.end());

        if (uniqueChars.size() != current.size()) {
            cout<<"....... this is "<<current<<endl;
            return;
        }

        result = max(result, static_cast<int>(current.size()));

        for (int i = index; i < arr.size(); ++i) {
            string newString =  current + arr[i];
            cout<<newString<<" ,"<<endl;
            backtrack(arr, i + 1, newString, result);
           
        }
    }

    int maxLength(vector<string>& arr) {
        int result = 0;
        backtrack(arr, 0, "", result);
        return result;
    }
    int main(){
        vector<string> input;
        input.push_back("un");
        input.push_back("iq");
        input.push_back("ue");
        input.push_back("fg");
        input.push_back("hz");
        maxLength(input);

    }


