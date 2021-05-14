#include <iostream>
#include <string>

int count_e(std::string row){
    int result = 0;
    for (const auto& c : row){
        result += c == 'e';
    }
    return result;

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
