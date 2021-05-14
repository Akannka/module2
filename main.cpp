#include <iostream>
#include <string>

//ex2(a)
/*
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
*/

//ex2(b)
#include <iostream>
#include <string>


class DynamicArray{
    int total_size;
    int current_size;
    float *arr;
public:
    DynamicArray(){
        total_size = 1;
        current_size = 0;
        arr = new float[total_size];
    }
    int get_size() const{
        return current_size;
    }
    float get_value(int index) const{
        if (index >= current_size){
            throw -1;
        }
        return arr[index];
    }
    void set_value(int index, float value){
        if (index >= current_size){
            throw -1;
        }
        arr[index] = value;
    }
    void add_value(float value){
        if (current_size == total_size){
            total_size += (total_size + 1) / 2;
            auto *new_arr = new float [total_size];
            for (int i = 0; i < current_size; i++){
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        for (int i = current_size; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        current_size++;
    }
    std::string to_string(){
        std::string result;
        for (int i = 0; i < get_size(); i++){
            result += std::to_string(arr[i]) + ' ';
        }
        return result;
    }
};

int main() {
    auto x = DynamicArray();
    std::cout << "empty arr: " << x.to_string() << std::endl;

    std::cout << "add 1.4 and -2.5" << std::endl;
    x.add_value(1.4f);
    x.add_value(-2.5f);
    std::cout << "arr[0]: " << x.get_value(0) << std::endl;
    std::cout << "arr: " << x.to_string() << std::endl;

    std::cout << "set arr[1]=5" << std::endl;
    x.set_value(1, 5);
    std::cout << x.to_string() << std::endl;
    std::cout << "arr: " << x.to_string() << std::endl;

    std::cout << "add 5, 6, 7, 8" << std::endl;
    x.add_value(5);
    x.add_value(6);
    x.add_value(7);
    x.add_value(8);
    std::cout << "arr: " << x.to_string() << std::endl;
    try{

        std::cout << "*getting arr[6]*" << std::endl;
        std::string result = "arr[6]: " + std::to_string(x.get_value(6));
        std::cout << result << std::endl;
    }
    catch (int){
        std::cout << "error" << std::endl;
    }
    return 0;
}
