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

User* ModelImpl::createUser(string name, string email, string cpf, string password, const vector<Course*>& courses, int permission) {
    return new UserImpl(name, email, cpf, password, courses, permission);
}

bool ModelImpl::removeUser(User* user) {
    for(auto it : this->users) {
        if(it->getEmail() == user->getEmail()) {
            this->users.erase(
                remove(
                    this->users.begin(),
                    this->users.end(),
                    it
                ),
                this->users.end()
            );
            return true;
        }
    };
    return false;
}

void ModelImpl::updateUser(User* user, string name, string email, string cpf) {
    user->setName(name);
    user->setEmail(email);
    user->setCPF(cpf);
}

User *ModelImpl::getUser() const {
    return user;
}

void ModelImpl::setUser(User *value) {
    user = value;
}

vector<User*>& ModelImpl::getUserList() {
    return users;
}

void ModelImpl::setUserList(const vector<User*> &value) {
    users = value;
}