#include "unit_user.h"
#include <iostream>

void unit_user_constructor() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    assert(user_1->getName() == "New User");

    User* user_2 = new UserImpl((UserImpl*) user_1);

    assert(user_2->getName() == "New User");
    assert(user_2->getEmail() == "user@email.com");
    assert(user_2->getCPF() == "12345678909");
    assert(user_2->getPassword() == "123");
    assert(user_2->getPermission() == 0);

    delete user_1;
    delete user_2;
}

void unit_user_destructor(){};

void unit_user_getName() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    assert(user_1->getName() == "New User");

    delete user_1;
}

void unit_user_setName() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    user_1->setName("Another User");

    assert(user_1->getName() == "Another User");

    delete user_1;
}

void unit_user_getEmail() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    assert(user_1->getEmail() == "user@email.com");

    delete user_1;
}

void unit_user_setEmail() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    user_1->setEmail("user_1@email.com");

    assert(user_1->getEmail() == "user_1@email.com");

    delete user_1;
}

void unit_user_getCPF() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    assert(user_1->getCPF() == "12345678909");

    delete user_1;
}

void unit_user_setCPF() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    user_1->setCPF("98765432109");

    assert(user_1->getCPF() == "98765432109");

    delete user_1;
}

void unit_user_getPassword() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    assert(user_1->getPassword() == "123");

    delete user_1;
}

void unit_user_setPassword() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    user_1->setPassword("321");

    assert(user_1->getPassword() == "321");

    delete user_1;
}

void unit_user_getPermission() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    assert(user_1->getPermission() == 0);

    delete user_1;
}

void unit_user_setPermission() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    user_1->setPermission(1);

    assert(user_1->getPermission() == 1);

    delete user_1;
}

void unit_user_assignment() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    vector<Course*> courses;
    courses.push_back(course_1);

    User* user_1 = new UserImpl("New User", "user@email.com", "12345678909", "123", courses, 0);

    User* user_2 = new UserImpl();

    *user_2 = *user_1;

    assert(user_2->getName() == "New User");
    assert(user_2->getEmail() == "user@email.com");
    assert(user_2->getCPF() == "12345678909");
    assert(user_2->getPassword() == "123");
    assert(user_2->getPermission() == 0);

    delete user_1;
    delete user_2;
}

void run_unit_tests_user() {
    unit_user_constructor();
    unit_user_destructor();
    unit_user_getName();
    unit_user_setName();
    unit_user_getEmail();
    unit_user_setEmail();
    unit_user_getCPF();
    unit_user_setCPF();
    unit_user_getPassword();
    unit_user_setPassword();
    unit_user_getPermission();
    unit_user_setPermission();
    unit_user_assignment();
}
