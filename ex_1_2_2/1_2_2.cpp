#include<iostream>
#include<algorithm>
#include<string>


bool has_uppercase(std::string& password){
    for(char c : password){
        if(isupper(c)){
            return true;
        }
    }
    std::cout << "No uppercase letter found. " << std::endl;
    return false;
}
bool has_lowercase(std::string& password){
    for(char c : password){
        if(islower(c)){
            return true;
        }
    }
    std::cout << "No lowercase letter found. " << std::endl;
    return false;

}
bool has_digit(std::string& password){
    for(char c : password){
        if(isdigit(c)){
            return true;
        }
    }
    std::cout << "No digit found. " << std::endl;
    return false;

}
bool has_special_char(std::string& password){
    for(char c : password){
        if(ispunct(c)){
            return true;
        }
    }
    std::cout << "No speacial character found. " << std::endl;
    return false;

}
std::string ask_user_pw(){
    std::string password = "";
    std::cout << "Input a new password: ";
    std::cin >> password;
    return password;
}
bool is_pw_long(std::string& password){
    if(password.size() < 8){
        std::cout << "Password is too short. " << std::endl;
        return false;
    }
    return true;
}



int main()
{
    std::string password = ask_user_pw();

    if(is_pw_long(password),
    has_uppercase(password),
    has_lowercase(password),
    has_digit(password),
    has_special_char(password))
    {
     std::cout << "Password approved. ";
    }

 return 0;
}