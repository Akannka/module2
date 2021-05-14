#include <iostream>
#include <string>

int count_e(std::string row){
    int result = 0;
    for (const auto& c : row){
        result += c == 'e';
    }
    return result;
}

int count_e_without_r(const std::string& row){
    int result=0;
    std::size_t len = row.length();
    for(int i = 0; i<len; i++){
        result += row[i] == 'e';
        result-=i<len-1 && row[i+1] == 'r';
    }
    return result;
}


int main() {
    std::string word;
    std::cin >> word;
    std:: cout << count_e(word) << ", " << count_e_without_r(word);
    return 0;
}
