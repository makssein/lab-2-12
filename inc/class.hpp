#include <iostream>
#include <memory>
#include <vector>
#define MY_DEBUG

class teacher;
class student{
public:

    student(const std::string &name) : m_studentName(name) {
#ifdef MY_DEBUG
        std::cout << "student " << m_studentName << " created" << std::endl;
#endif
    }
    ~student(){
#ifdef MY_DEBUG
        std::cout << "student " << m_studentName << " deleted" << std::endl;
#endif
    }

    const std::shared_ptr<teacher> getTeacher() { return m_teacher; }
    const std::string& getName() const { return m_studentName; }
    friend void addStudentToTeacher(std::shared_ptr<teacher>& Teacher, std::shared_ptr<student>& Student);

private:
    std::string m_studentName;
    std::shared_ptr<teacher> m_teacher;
};

class teacher{
public:
    teacher(const std::string& name) : m_teacherName(name) {
#ifdef MY_DEBUG
        std::cout << "teacher " << m_teacherName << " created" << std::endl;
#endif
    }
    ~teacher(){
#ifdef MY_DEBUG
        std::cout << "teacher " << m_teacherName << " deleted" << std::endl;
#endif
    }
    void addStudent(std::shared_ptr<student>& Student) {
        m_students.push_back(Student);
    }

    void getAllStudents() {
        if(!m_students.empty()) {
            std::cout << "All students teachers " + m_teacherName + ": " << std::endl;
            for (auto const &student: m_students)
                std::cout << student->getName() << std::endl;
        }
        else{
            std::cout << "Teacher " + m_teacherName + " has no students" << std::endl;
        }
    }

    const std::string& getName() const { return m_teacherName; }

    friend void addStudentToTeacher(std::shared_ptr<teacher>& Teacher, std::shared_ptr<student>& Student);

private:
    std::string m_teacherName;
    std::vector<std::shared_ptr<student>> m_students;

};

void addStudentToTeacher(std::shared_ptr<teacher>& Teacher, std::shared_ptr<student>& Student) {
    Student->m_teacher = Teacher;
    Teacher->addStudent(Student);
}

















