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
            throw;
        }
        return arr[index];
    }
    void set_value(int index, float value){
        if (index >= current_size){
            throw;
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
    }
    std::string to_string(){
        std::string result;
        for (int i = 0; i < get_size(); i++){
            result += std::to_string(arr[i]) + ' ';
        }
        return result;
    }

};
