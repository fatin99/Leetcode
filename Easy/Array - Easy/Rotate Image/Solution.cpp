#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int count = 0; count < 3; count += 1) {
            for (int i = 0; i < size/2; i += 1) {
                for (int j = i; j < size - i - 1; j += 1) {
                    int temp = matrix.at(i).at(j);
                    matrix.at(i).at(j) = matrix.at(j).at(size - i - 1);
                    matrix.at(j).at(size - i - 1) = matrix.at(size - i - 1).at(size - j - 1);
                    matrix.at(size - i - 1).at(size - j - 1) = matrix.at(size - j - 1).at(i);
                    matrix.at(size - j - 1).at(i) =  temp;
                }
            }
        }
    }
};

void print(vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<vector<int>> matrix {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    solution.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        print(matrix.at(i));
        cout << endl;
    }
    return 0;
}
