#include "unit_course.h"
#include <iostream>

void unit_course_constructor() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");

    assert(course_1->getName() == "New Course");
    assert(course_1->getDescription() == "Course Description");
    assert(course_1->getPrice() == "10,00");

    Course* course_2 = new CourseImpl((CourseImpl*) course_1);

    assert(course_2->getName() == "New Course");
    assert(course_2->getDescription() == "Course Description");
    assert(course_2->getPrice() == "10,00");

    delete course_1;
    delete course_2;
}

void unit_course_destructor(){}

void unit_course_getName() {
    Course* course = new CourseImpl("New Course", "Course Description", "10,00");

    assert(course->getName() == "New Course");

    delete course;
}

void unit_course_setName() {
     Course* course = new CourseImpl("New Course", "Course Description", "10,00");

     course->setName("Another Course");

     assert(course->getName() == "Another Course");

     delete course;
}

void unit_course_getDescription() {
    Course* course = new CourseImpl("New Course", "Course Description", "10,00");

    assert(course->getDescription() == "Course Description");

    delete course;
}

void unit_course_setDescription() {
    Course* course = new CourseImpl("New Course", "Course Description", "10,00");

    course->setDescription("Course Description 1");

    assert(course->getDescription() == "Course Description 1");

    delete course;
}

void unit_course_getPrice() {
    Course* course = new CourseImpl("New Course", "Course Description", "10,00");

    assert(course->getPrice() == "10,00");

    delete course;
}

void unit_course_setPrice() {
    Course* course = new CourseImpl("New Course", "Course Description", "10,00");

    course->setPrice("22,00");

    assert(course->getPrice() == "22,00");

    delete course;
}

void unit_course_assignment() {
    Course* course_1 = new CourseImpl("New Course", "Course Description", "10,00");
    Course* course_2 = new CourseImpl();

    *course_2 = *course_1;

    assert(course_2->getName() == "New Course");
    assert(course_2->getDescription() == "Course Description");
    assert(course_2->getPrice() == "10,00");

    delete course_1;
    delete course_2;
}

void run_unit_tests_course() {
    unit_course_constructor();
    unit_course_destructor();
    unit_course_getName();
    unit_course_setName();
    unit_course_getDescription();
    unit_course_setDescription();
    unit_course_getPrice();
    unit_course_setPrice();
    unit_course_assignment();
}

