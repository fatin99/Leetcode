#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size()/2; i ++) {
            char temp = s.at(i);
            s.at(i) = s.at(s.size()-1-i);
            s.at(s.size()-1-i) = temp;
        }
    }
};

void print(vector<char> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<char> s{'H','a','n','n','a', 'h'};
    solution.reverseString(s);
    print(s);
    return 0;
}