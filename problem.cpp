#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::cout << "Enter numbers separated by spaces: ";
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::vector<int> nums;
    int num;

    while (ss >> num) {
        nums.push_back(num);
    }

    if (nums.empty()) return 0;

    std::vector<int> currentSeq;
    std::vector<int> maxSeq;
    int maxVal = nums[0];

    for (int n : nums) {
        if (currentSeq.empty()) {
            currentSeq.push_back(n);
            maxVal = n;
        } else if (n <= maxVal) {
            // Continue the sequence
            currentSeq.push_back(n);
        } else {
            // Reset sequence if n > maxVal
            if (currentSeq.size() > maxSeq.size()) {
                maxSeq = currentSeq;
            }
            currentSeq = {n};
            maxVal = n;
        }

        if (n > maxVal) maxVal = n;
    }

    // Check last sequence
    if (currentSeq.size() > maxSeq.size()) {
        maxSeq = currentSeq;
    }

    // Print the greatest subsequence
    std::cout << "Greatest subsequence: ";
    for (int x : maxSeq) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
