#include "inc/class.hpp"

int main() {
    auto Teacher { std::make_shared<teacher>("Teacher") };
    auto Student_1 { std::make_shared<student>("Student_1") };
    auto Student_2 { std::make_shared<student>("Student_2") };
    addStudentToTeacher(Teacher, Student_1);
    addStudentToTeacher(Teacher, Student_2);

    Teacher->getAllStudents();

    return 0;
}
