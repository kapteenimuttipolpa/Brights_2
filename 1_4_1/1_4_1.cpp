#include<iostream>
#include<string>
#include<cctype>
#include<cassert>

std::string capitalize_string(const std::string& s) {
    std::string result = s;
    bool capitalize_next = true;

    for (size_t i = 0; i < result.size(); i++) {
        if (std::isspace(result[i])) {
            capitalize_next = true;
        }
        else if (capitalize_next) {
            result[i] = toupper(result[i]);
            capitalize_next = false;
        }
        else {
            result[i] = tolower(result[i]);
        }
    }

    return result;
}
int main() {
    assert("The String Challenge" ==
    capitalize_string("the string challenge"));
    std::cout << "Test 1 passed" << std::endl;
    assert("This Is An Example, Should Work!" ==
    capitalize_string("THIS IS an ExamplE, should wORk!"));
    std::cout << "Test 2 passed" << std::endl;
    return 0;
}