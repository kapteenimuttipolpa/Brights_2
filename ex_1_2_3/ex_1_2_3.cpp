#include<iostream>
#include<string>
#include<vector>
#include<climits>
struct Student{
    std::string name;
    int age;
    int grade;
};

int ask_student_amount()
{
    int students = 0;
    std::cout << "How many student do you want to input?: ";
    std::cin >> students;
    return students;

}
std::vector<Student*> fill_student_info(int students)
{   
   
    std::vector<Student*> student_vec = {};
    int i = 0;
    while(i != students){
        Student* student = new Student();
        std::cout << "Insert students name: ";
        std::cin >> student->name;
        std::cout << "Insert students age: ";
        std::cin >> student->age;
        std::cout << "Insert students grade: ";
        std::cin >> student->grade;
        student_vec.push_back(student);
        i++;
    }
    return student_vec;
}
void print_average_grade(std::vector<Student*>& student_vec){
    int grades_combined = 0;
    for(auto student : student_vec){
        grades_combined += student->grade;
    }
    std::cout << "Average grade: " << grades_combined / student_vec.size() << std::endl;
}
/*
Funktio tulostaa korkeimman arvosanan saaneen.
*/
void print_highest_score(std::vector<Student*>& student_vec){
    Student* highest_scorer = student_vec.at(0);
    for(auto student : student_vec){
        highest_scorer = std::max(student, highest_scorer);
    }
    std::cout << "The highest scoring student is : " << highest_scorer->name;
    std::cout << std::endl;
}

int main()
{
    int students = ask_student_amount();
    std::vector<Student*> student_vec = fill_student_info(students);
    print_average_grade(student_vec);
    print_highest_score(student_vec);
    for(auto& student : student_vec){
        delete student;
    }
 return 0;
}

