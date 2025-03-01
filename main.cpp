#include <iostream>
#include <vector>

using namespace std;

struct FindMin {
    int operator()(const vector<int>& nums) const {
        int minVal = nums[0];
        for (int num : nums) {
            if (num < minVal) {
                minVal = num;
            }
        }
        return minVal;
    }
};

struct FindMax {
    int operator()(const vector<int>& nums) const {
        int maxVal = nums[0];
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        return maxVal;
    }
};

struct Descending {
    void operator()(vector<int>& nums) const {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};

struct Ascending {
    void operator()(vector<int>& nums) const {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};

struct Increase {
    int value;
    Increase(int val) : value(val) {}
    void operator()(vector<int>& nums) const {
        for (int& num : nums) {
            num += value;
        }
    }
};

struct Decrease {
    int value;
    Decrease(int val) : value(val) {}
    void operator()(vector<int>& nums) const {
        for (int& num : nums) {
            num -= value;
        }
    }
};

struct RemoveValue {
    int value;
    RemoveValue(int val) : value(val) {}
    void operator()(vector<int>& nums) const {
        nums.erase(remove(nums.begin(), nums.end(), value), nums.end());
    }
};

int main() {
    vector<int> numbers = { 5, 3, 8, 1, 6, 8, 7 };

    // Пошук мінімального значення
    FindMin findMin;
    cout << "Minimum value: " << findMin(numbers) << endl;

    // Пошук максимального значення
    FindMax findMax;
    cout << "Maximum value: " << findMax(numbers) << endl;

    // Сортування за спаданням
    Descending descending;
    descending(numbers);
    cout << "Sorted in descending order: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    // Сортування за зростанням
    Ascending ascending;
    ascending(numbers);
    cout << "Sorted in ascending order: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    // Збільшення значень на 2
    Increase increase(2);
    increase(numbers);
    cout << "After increasing by 2: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    // Зменшення значень на 1
    Decrease decrease(1);
    decrease(numbers);
    cout << "After decreasing by 1: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    // Видалення елементів, рівних 8
    RemoveValue remove(8);
    remove(numbers);
    cout << "After removing 8: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    return 0;
}
