#include <iostream>
#include <vector>

int main() {
    const int keys[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
    int table[13] = {};
    bool occupied[13] = {};

    for (int key : keys) {
        int address = key % 13;
        while (occupied[address]) {
            address = (address + 1) % 13;
        }
        table[address] = key;
        occupied[address] = true;
    }

    std::cout << "Address Key\n";
    for (int i = 0; i < 13; ++i) {
        std::cout << i << " ";
        if (occupied[i]) {
            std::cout << table[i];
        } else {
            std::cout << "empty";
        }
        std::cout << '\n';
    }

    for (int target : {1, 84}) {
        int address = target % 13;
        int comparisons = 0;
        while (occupied[address]) {
            ++comparisons;
            if (table[address] == target) {
                break;
            }
            address = (address + 1) % 13;
        }
        std::cout << "Search " << target << ": " << comparisons
                  << " comparisons\n"; // 2 3
    }

    return 0;
}
