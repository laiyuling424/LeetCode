//
// Created by 赖於领 on 2021/7/18.
//

#include "Student.h"

Student* Student::instance = 0;

Student*Student::getInstance() {
    if(!instance){
        instance = new Student();
    }
    return instance;
}

Student::Student() {

}

Student::Student(int age) {
    this->age = age;
}

