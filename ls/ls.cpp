#include <iostream>
#include <experimental/filesystem>

int main() {
    for (auto& p: std::experimental::filesystem::recursive_directory_iterator("/")) {
        std::cout << p << '\n';
    }
}
