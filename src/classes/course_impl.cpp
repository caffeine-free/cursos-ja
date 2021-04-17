#include "course_impl.h"

CourseImpl::CourseImpl() {}

CourseImpl::CourseImpl(Course* course) {
    this->name = course->getName();
    this->description = course->getDescription();
    this->price = course->getPrice();
}

CourseImpl::CourseImpl(
    string name,
    string description,
    string price
) {
    this->name = name;
    this->description = description;
    this->price = price;
}

CourseImpl::~CourseImpl() {}

string CourseImpl::getName() const {
    return this->name;
}

void CourseImpl::setName(const string& name) {
    this->name = name;
}

string CourseImpl::getDescription() const {
    return this->description;
}

void CourseImpl::setDescription(const string& description) {
    this->description = description;
}

string CourseImpl::getPrice() const {
    return this->price;
}

void CourseImpl::setPrice(const string& price) {
    this->price = price;
}

Course& CourseImpl::operator=(Course& course) {
    if(this == &course)
            return *this;

    this->name = course.getName();
    this->description = course.getDescription();
    this->price = course.getPrice();

    return *this;
}

