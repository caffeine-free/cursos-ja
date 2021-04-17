#include "user_impl.h"

UserImpl::UserImpl() {}

UserImpl::UserImpl(User* user) {
    this->name = user->getName();
    this->email = user->getEmail();
    this->cpf = user->getCPF();
    this->password = user->getPassword();
    this->courses = user->getCourses();
    this->permission = user->getPermission();
}

UserImpl::UserImpl(
    string name,
    string email,
    string cpf,
    string password,
    const vector<Course*>& courses,
    int permission
) {
    this->name = name;
    this->email = email;
    this->cpf = cpf;
    this->password = password;
    this->courses = courses;
    this->permission = permission;
}

UserImpl::~UserImpl() {}

string UserImpl::getName() const {
    return name;
}

void UserImpl::setName(const string &value) {
    name = value;
}

string UserImpl::getEmail() const {
    return email;
}

void UserImpl::setEmail(const string &value) {
    email = value;
}

void UserImpl::setCPF(const string &value) {
    cpf = value;
}

string UserImpl::getCPF() const {
    return cpf;
}

void UserImpl::setPassword(const string &value) {
    password = value;
}

string UserImpl::getPassword() const {
    return password;
}

vector<Course*>& UserImpl::getCourses() {
    return courses;
}

void UserImpl::setCourses(const vector<Course*> &value) {
    courses = value;
}

int UserImpl::getPermission() const {
    return permission;
}

void UserImpl::setPermission(int value) {
    permission = value;
}

User& UserImpl::operator=(User& user) {
    if (this == &user)
        return *this;

    this->name = user.getName();
    this->email = user.getEmail();
    this->cpf = user.getCPF();
    this->password = user.getPassword();
    this->courses = user.getCourses();
    this->permission = user.getPermission();

    return *this;
}

bool UserImpl::operator==(User& rhs) {
    return this->name == rhs.getName()
        && this->email == rhs.getEmail()
        && this->cpf == rhs.getCPF()
        && this->password == rhs.getPassword()
        && this->permission == rhs.getPermission();
}
