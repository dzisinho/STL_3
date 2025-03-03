#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct FindMin {
    T operator()(const vector<T>& nums) const {
        T minVal = nums[0];
        for (const T& num : nums)
            if (num < minVal) minVal = num;
        return minVal;
    }
};

template <typename T>
struct FindMax {
    T operator()(const vector<T>& nums) const {
        T maxVal = nums[0];
        for (const T& num : nums)
            if (num > maxVal) maxVal = num;
        return maxVal;
    }
};

template <typename T>
struct Sort {
    bool ascending;
    Sort(bool asc) : ascending(asc) {}
    void operator()(vector<T>& nums) const {
        for (size_t i = 0; i < nums.size() - 1; ++i)
            for (size_t j = i + 1; j < nums.size(); ++j)
                if ((ascending && nums[i] > nums[j]) || (!ascending && nums[i] < nums[j]))
                    swap(nums[i], nums[j]);
    }
};

template <typename T>
struct Modify {
    T value;
    Modify(T val) : value(val) {}
    void operator()(vector<T>& nums, bool increase) const {
        for (T& num : nums)
            num += increase ? value : -value;
    }
};

template <typename T>
struct RemoveValue {
    T value;
    RemoveValue(T val) : value(val) {}
    void operator()(vector<T>& nums) const {
        vector<T> temp;
        for (const T& num : nums)
            if (num != value) temp.push_back(num);
        nums = temp;
    }
};

template <typename T>
void printVector(const vector<T>& nums) {
    for (const T& num : nums) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> numbers = { 5, 3, 8, 1, 6, 8, 7 };

    cout << "Min: " << FindMin<int>()(numbers) << endl;
    cout << "Max: " << FindMax<int>()(numbers) << endl;

    Sort<int>(false)(numbers);
    cout << "Sorted Descending: "; printVector(numbers);

    Sort<int>(true)(numbers);
    cout << "Sorted Ascending: "; printVector(numbers);

    Modify<int>(2)(numbers, true);
    cout << "Increased by 2: "; printVector(numbers);

    Modify<int>(1)(numbers, false);
    cout << "Decreased by 1: "; printVector(numbers);

    RemoveValue<int>(8)(numbers);
    cout << "Removed 8: "; printVector(numbers);

    return 0;
}
