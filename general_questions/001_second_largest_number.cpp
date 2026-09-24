#include <iostream>
#include <vector>

using namespace std;

int secondLargestNumber2N(vector<int>& nums) {
    int max = INT_MIN;
    int second_max = max;

    for (int num : nums) {
        if (num > max) {
            max = num;
        }
    }

    for (int num : nums) {
        if (num < max && num > second_max) {
            second_max = num;
        }
    }

    if (second_max != INT_MIN && second_max != max) return second_max;
    return -1;
}

int secondLargestNumberN(vector<int>& nums) {
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int num : nums) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        }
        else if (num < largest && num > second_largest) {
            second_largest = num;
        }
    }

    return second_largest = (second_largest != largest && second_largest != INT_MIN) ? second_largest : -1;
}

int main () {
    vector<vector<int>> nums = {
        {8, 8, 7, 6, 5},
        {1, 2, 3, 4, 5},
        {1, 1, 1, 1, 1},
    };

    for (vector<int> num_list : nums) {
        cout << "TC: ";
        for (int num : num_list) {
            cout << num << " ";
        }
        cout << "\n";
        cout << "O(2n): ";
        cout << secondLargestNumberN(num_list) << "\n";
        cout << "O(n): ";
        cout << secondLargestNumber2N(num_list) << "\n";
        cout << "-----------------------------------\n\n";
    }
}