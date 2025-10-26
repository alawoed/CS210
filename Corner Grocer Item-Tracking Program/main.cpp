/*
 * Project 3 – Corner Grocer Frequency Tracker
 * Author: David Alawoe
 * Date: Oct 16, 2025
 *
 * Purpose:
 *   Read a daily purchases file (CS210_Project_Three_Input_File.txt),
 *   count item frequencies, write a backup file (frequency.dat),
 *   and provide a menu to:
 *     1) query a single item’s frequency,
 *     2) print all items with counts,
 *     3) print a histogram (item + asterisks),
 *     4) exit.
 *
 * Design:
 *   - Class GroceryTracker encapsulates data and behavior.
 *   - Uses std::map<std::string,int> for counts.
 *   - Writes frequency.dat immediately after loading input.
 *   - Input validation for menu.
 *   - Clear inline comments for readability and maintenance.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

class GroceryTracker {
public:
    // Load items from input file and build frequency table
    bool LoadFromFile(const std::string& inputPath) {
        std::ifstream in(inputPath);
        if (!in) {
            std::cerr << "ERROR: Could not open input file: " << inputPath << "\n";
            return false;
        }
        // Read one item (single word per line) at a time
        std::string item;
        while (std::getline(in, item)) {
            // Strip any trailing carriage returns/spaces
            TrimRight(item);
            if (item.empty()) continue;
            ++freq_[item];  // increment count in O(log N) time
        }
        return true;
    }

    // Write frequency backup immediately (no user intervention)
    bool WriteBackup(const std::string& outputPath = "frequency.dat") const {
        std::ofstream out(outputPath);
        if (!out) {
            std::cerr << "ERROR: Could not write backup file: " << outputPath << "\n";
            return false;
        }
        for (const auto& kv : freq_) {
            out << kv.first << " " << kv.second << "\n";
        }
        return true;
    }

    // Lookup a single item’s frequency; returns 0 if not present
    int GetFrequency(const std::string& item) const {
        auto it = freq_.find(item);
        return (it == freq_.end()) ? 0 : it->second;
    }

    // Print all items and counts
    void PrintAll() const {
        for (const auto& kv : freq_) {
            std::cout << kv.first << " " << kv.second << "\n";
        }
    }

    // Print histogram: item followed by asterisks equal to its count
    void PrintHistogram() const {
        for (const auto& kv : freq_) {
            std::cout << std::left << std::setw(15) << kv.first << " ";
            for (int i = 0; i < kv.second; ++i) std::cout << '*';
            std::cout << "\n";
        }
    }

    // True if data is loaded (non-empty map)
    bool HasData() const { return !freq_.empty(); }

private:
    std::map<std::string, int> freq_;

    // Helper: trim trailing spaces/CR to handle Windows-style lines safely
    static void TrimRight(std::string& s) {
        while (!s.empty() && (s.back() == ' ' || s.back() == '\r' || s.back() == '\t'))
            s.pop_back();
    }
};

// ---------------------------
// Menu UI helpers
// ---------------------------

// Get a validated menu choice [1..4]
int GetMenuChoice() {
    while (true) {
        std::cout << "\n===== Corner Grocer Menu =====\n"
                  << "1. Lookup item frequency\n"
                  << "2. Print all item frequencies\n"
                  << "3. Print histogram\n"
                  << "4. Exit\n"
                  << "Choose an option (1-4): ";
        int choice;
        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear rest of line
            return choice;
        }
        // Bad input: clear and re-prompt
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid selection. Please enter 1, 2, 3, or 4.\n";
    }
}

// Prompt for an item (full line) to support names with spaces if needed later
std::string PromptItem() {
    std::cout << "Enter item to search: ";
    std::string item;
    std::getline(std::cin, item);
    // Keep behavior simple/case-sensitive per assignment; trim trailing spaces just in case
    while (!item.empty() && (item.back() == ' ' || item.back() == '\r' || item.back() == '\t'))
        item.pop_back();
    return item;
}

int main() {
    const std::string kInputFile = "CS210_Project_Three_Input_File.txt";

    GroceryTracker tracker;

    // 1) Load input and build frequencies
    if (!tracker.LoadFromFile(kInputFile)) {
        // If the file is missing, provide a friendly message and exit cleanly
        std::cerr << "Ensure the input file is in the same folder as the executable.\n";
        return 1;
    }

    // 2) Immediately write backup file frequency.dat (per spec)
    tracker.WriteBackup("frequency.dat");

    // 3) Main loop – menu-driven interaction
    while (true) {
        int choice = GetMenuChoice();

        if (choice == 1) {
            // Menu Option 1: Single item frequency lookup
            std::string item = PromptItem();
            int count = tracker.GetFrequency(item);
            std::cout << item << " " << count << "\n";
        } else if (choice == 2) {
            // Menu Option 2: Print all items with counts
            tracker.PrintAll();
        } else if (choice == 3) {
            // Menu Option 3: Print histogram
            tracker.PrintHistogram();
        } else { // choice == 4
            // Menu Option 4: Exit
            std::cout << "Exiting program.\n";
            break;
        }
    }

    return 0;
}