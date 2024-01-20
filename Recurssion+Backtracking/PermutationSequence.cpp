// #include <vector>
// #include <string>

// class Solution {
// public:

//     void generateAllPermutations(string permutation, vector<string>& finalans, int index) {

//         if (index == permutation.size()) {
//             finalans.push_back(permutation);
//             return;
//         }

//         for (int i = index; i < permutation.size(); i++) {
//             swap(permutation[i], permutation[index]);
//             generateAllPermutations(permutation, finalans, index + 1);
//             swap(permutation[i], permutation[index]);
//         }

//     }

//     string getPermutation(int n, int k) {

//         string permutation = "";

//         for (int i = 1; i <= n; i++) {
//             permutation += to_string(i);
//         }

//         vector<string> finalans;
//         generateAllPermutations(permutation, finalans, 0);
//         sort(finalans.begin(),finalans.end());
//         return finalans[k - 1]; // Return the kth permutation (0-indexed)
//     }
// };


//here is the optimized version of this code
class Solution {
public:
    string getPermutation(int n, int k) {
           int fact = 1; 
        vector<int> numbers; 
        for(int i = 1;i<n;i++) {
            fact = fact * i; 
            numbers.push_back(i); 
        }
        numbers.push_back(n); 
        string ans = ""; 
        k = k - 1; 
        while(true) {
            ans = ans + to_string(numbers[k / fact]); 
            numbers.erase(numbers.begin() + k / fact); 
            if(numbers.size() == 0) {
                break; 
            }
            
            k = k % fact; 
            fact = fact / numbers.size();
        }
        return ans; 
        
    }
};