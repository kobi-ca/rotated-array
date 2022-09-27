#include <iostream>
#include <array>
#include <optional>

namespace {
    std::optional<int> find_midpoint(const std::array<int, 10>& arr) {
        if (arr.empty()) {
            return std::nullopt;
        }
        auto sz = static_cast<int>(arr.size());
        auto low = 0;
        auto high = sz -  1;
        while(low < high) {
            auto midpoint = (high + low + 1) / 2;
            if (arr[midpoint] < arr[midpoint - 1]) {
                return midpoint;
            }
            if (arr[low] > arr[midpoint]) {
                high = midpoint;
            } else {
                low = midpoint;
            }
        }
        return std::nullopt;
    }
}

int main() {
    {
        const std::array<int, 10> arr{4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
        const auto opt = find_midpoint(arr);
        if (opt) {
            std::clog << "partition point is " << *opt << " elem is " << arr[*opt] << '\n';
        } else {
            std::clog << "not rotated\n";
        }
    }
    {
        const std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        const auto opt = find_midpoint(arr);
        if (opt) {
            std::clog << "partition point is " << *opt << " elem is " << arr[*opt] << '\n';
        } else {
            std::clog << "not rotated\n";
        }
    }
}
