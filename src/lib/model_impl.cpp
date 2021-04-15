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

vector<Course*>& ModelImpl::getCourses() {
    return this->courses;
}

void ModelImpl::setCourses(const vector<Course*>& courses) {
    this->courses = courses;
}

void ModelImpl::add(Course* course) {
    this->courses.push_back(course);
}
