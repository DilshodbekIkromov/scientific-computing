#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

// —————————————————————————————————————————————————————————
// Type aliases for clarity
using PhoneBook           = std::map<std::string, int>;
using ReversePhoneBook    = std::multimap<int, std::string>;
using ContactInfo         = std::tuple<int, std::string>;
using PhoneBookWithEmail  = std::map<std::string, ContactInfo>;

// —————————————————————————————————————————————————————————
// 1. Initialize with an initializer_list
PhoneBook initPhoneBook() {
    return PhoneBook{
        {"Alice",   5551234},
        {"Bob",     5555678},
        {"Charlie", 5559012},
        {"Diana",   5551234}   // note: duplicate number
    };
}

// —————————————————————————————————————————————————————————
// 2a. Print entries via range-based for
void printEntriesRange(const PhoneBook &pb) {
    std::cout << "Phone book (range‐for):\n";
    for (const auto &[name, number] : pb) {
        std::cout << "  " << name << " → " << number << "\n";
    }
}

// —————————————————————————————————————————————————————————
// 2b. Print entries via std::for_each + lambda
void printEntriesForEach(const PhoneBook &pb) {
    std::cout << "\nPhone book (for_each + lambda):\n";
    std::for_each(pb.begin(), pb.end(),
        [](const auto &entry){
            std::cout << "  " 
                      << entry.first 
                      << " ⇒ " 
                      << entry.second 
                      << "\n";
        });
}

// —————————————————————————————————————————————————————————
// 3. Gather all names into a vector
std::vector<std::string> getAllNames(const PhoneBook &pb) {
    std::vector<std::string> names;
    names.reserve(pb.size());
    for (const auto &[name, _] : pb)
        names.push_back(name);
    return names;
}

// —————————————————————————————————————————————————————————
// 4. Gather all numbers into a vector
std::vector<int> getAllNumbers(const PhoneBook &pb) {
    std::vector<int> numbers;
    numbers.reserve(pb.size());
    for (const auto &[_, num] : pb)
        numbers.push_back(num);
    return numbers;
}

// —————————————————————————————————————————————————————————
//    Detect duplicates by inserting into a set and
//    checking if insertion ever fails.
bool hasDuplicateNumbers(const std::vector<int> &numbers) {
    std::set<int> seen;
    for (int num : numbers) {
        if (!seen.insert(num).second)
            return true;  // already in the set ⇒ duplicate
    }
    return false;
}

// —————————————————————————————————————————————————————————
// 5/6. Build the “reverse” multimap: number → name(s)
ReversePhoneBook makeReverse(const PhoneBook &pb) {
    ReversePhoneBook rev;
    for (const auto &[name, num] : pb)
        rev.emplace(num, name);
    return rev;
}

// —————————————————————————————————————————————————————————
// 7. Initialize and print a map of name → (number, email)
PhoneBookWithEmail initPhoneBookWithEmail() {
    return PhoneBookWithEmail{
        {"Alice",   {5551234, "alice@example.com"}},
        {"Bob",     {5555678, "bob@example.com"}},
        {"Charlie", {5559012, "charlie@domain.org"}}
    };
}

void printWithEmail(const PhoneBookWithEmail &pb) {
    std::cout << "\nPhone book with emails:\n";
    for (const auto &[name, info] : pb) {
        auto &[num, email] = const_cast<ContactInfo&>(info);
        std::cout << "  " << name 
                  << " → " << num 
                  << ", " << email 
                  << "\n";
    }
}

// —————————————————————————————————————————————————————————
// Main: demonstrate everything
int main() {
    // 1. Init
    auto pb = initPhoneBook();

    // 2. Print
    printEntriesRange(pb);
    printEntriesForEach(pb);

    // 3. Extract names
    auto names = getAllNames(pb);
    std::cout << "\nAll names:";
    for (auto &n : names) std::cout << " " << n;
    std::cout << "\n";

    // 4. Extract numbers + check duplicates
    auto numbers = getAllNumbers(pb);
    std::cout << "Duplicates present? "
              << (hasDuplicateNumbers(numbers) ? "Yes" : "No")
              << "\n";

    // 5/6. Reverse lookup
    auto rev = makeReverse(pb);
    std::cout << "\nReverse map (number → name):\n";
    for (const auto &[num, name] : rev)
        std::cout << "  " << num << " ⇒ " << name << "\n";

    // 7. Map with tuple (number,email)
    auto pbEmail = initPhoneBookWithEmail();
    printWithEmail(pbEmail);

    return 0;
}
