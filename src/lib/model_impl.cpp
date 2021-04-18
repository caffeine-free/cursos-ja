#include "model_impl.h"

ModelImpl::ModelImpl() {}

ModelImpl::~ModelImpl() {}

Model* Model::createModel() {
    return ModelImpl::createModel();
}

Model* ModelImpl::createModel() {
    Model* model = new ModelImpl();

    model->setUser(nullptr);

    model->readUser("../cursos-ja/database/users.csv");
    model->readCourse("../cursos-ja/database/courses.csv");

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

void ModelImpl::add(User* user) {
    this->users.push_back(user);
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

void ModelImpl::updateUser(User* user, string name, string email, string cpf, string password) {
    user->setName(name);
    user->setEmail(email);
    user->setCPF(cpf);
    user->setPassword(password);
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

bool ModelImpl::writeCourse(const string& file){
    ofstream output_file;

    output_file.open(file, ios::out);

    for (auto it : this->courses) {
        output_file << it->getName() << ";"
                    << it->getDescription() << ";"
                    << it->getPrice() << "\n";
    }

    output_file.close();

    return output_file.good();
}

bool ModelImpl::readCourse(const string& file){
    ifstream input_file;
    vector<Course*> courses;

    input_file.open(file, ios::in);

    string name, description, price;

    while(getline(input_file, name, ';')){

        getline(input_file, description, ';');

        getline(input_file, price);

        Course* course = this->createCourse(
            name, description, price
        );

        courses.push_back(course);
    }

    this->setCourses(courses);

    input_file.close();

    return input_file.good();
}

bool ModelImpl::writeUser(const string& file){
    ofstream output_file;

    output_file.open(file, ios::out);

    for (auto it : this->users) {
        output_file << it->getName() << ";"
                    << it->getEmail() << ";"
                    << it->getCPF() << ";"
                    << it->getPassword() << ";";
        for (auto courses : it->getCourses()){
            output_file << courses->getName() << ";"
                        << courses->getDescription() << ";"
                        << courses->getPrice() << ";";
        }

        output_file << it->getPermission() << "\n";
    }

    output_file.close();

    return output_file.good();
}

bool ModelImpl::readUser(const string& file){
    ifstream input_file;
    vector<User*> users;
    vector<string> courses_aux;
    Course* course_1;
    Course* course_2;
    Course* course_3;
    Course* course_4;
    Course* course_5;

    input_file.open(file, ios::in);

    string name, email, cpf, password, course_name, course_description, course_price, permission;

    while(getline(input_file, name, ';')){

        getline(input_file, email, ';');

        getline(input_file, cpf, ';');

        getline(input_file, password, ';');

        getline(input_file, course_name, ';');

        getline(input_file, course_description, ';');

        getline(input_file, course_price, ';');

        course_1 = createCourse(course_name, course_description, course_price);

        getline(input_file, course_name, ';');

        getline(input_file, course_description, ';');

        getline(input_file, course_price, ';');

        course_2 = createCourse(course_name, course_description, course_price);

        getline(input_file, course_name, ';');

        getline(input_file, course_description, ';');

        getline(input_file, course_price, ';');

        course_3 = createCourse(course_name, course_description, course_price);

        getline(input_file, course_name, ';');

        getline(input_file, course_description, ';');

        getline(input_file, course_price, ';');

        course_4 = createCourse(course_name, course_description, course_price);

        getline(input_file, course_name, ';');

        getline(input_file, course_description, ';');

        getline(input_file, course_price, ';');

        course_5 = createCourse(course_name, course_description, course_price);

        vector<Course*> courses;
        courses.push_back(course_1);
        courses.push_back(course_2);
        courses.push_back(course_3);
        courses.push_back(course_4);
        courses.push_back(course_5);

        getline(input_file, permission);

        User* user = this->createUser(
            name, email, cpf, password, courses, stoi(permission)
        );

        users.push_back(user);
    }

    this->setUserList(users);

    input_file.close();

    return input_file.good();
}

