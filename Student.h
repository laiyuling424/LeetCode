//
// Created by 赖於领 on 2021/7/18.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H


class Student {
private:
    static Student *instance;
    Student();

    int age;
public:
    char *name;

    Student(int age);

    static Student *getInstance();

    void friend setAge(Student *student);

    Student operator+(const Student &student) {
        Student temp;
        temp.age = this->age + student.age;
        return temp;
    };

    int getAge(){
        return age;
    }
};


#endif //UNTITLED_STUDENT_H
