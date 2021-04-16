#include "model_impl.h"

ModelImpl::ModelImpl() {}

ModelImpl::~ModelImpl() {}

Model* Model::createModel() {
    return ModelImpl::createModel();
}

Model* ModelImpl::createModel() {
    Model* model = new ModelImpl();
    return model;
}

Course* ModelImpl::createCourse(string name, string description, string price) {
    return new CourseImpl(name, description, price);
}

bool ModelImpl::removeCourse(Course* course) {
    for(auto it : this->courses) {
        if(it->getName() == course->getName()) {
            this->courses.erase(
                remove(
                    this->courses.begin(),
                    this->courses.end(),
                    it
                ),
                this->courses.end()
            );
            return true;
        }
    };
    return false;
}

void ModelImpl::updateCourse(Course* course, string name, string description, string price) {
    course->setName(name);
    course->setDescription(description);
    course->setPrice(price);
}

vector<Course*>& ModelImpl::getCourses() {
    return this->courses;
}

void ModelImpl::setCourses(const vector<Course*>& courses) {
    this->courses = courses;
}

void ModelImpl::add(Course* course) {
    this->courses.push_back(course);
}
