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

User* ModelImpl::createUser(
    string name,
    string email,
    string cpf,
    string password,
    const vector<bool>& courses,
    int permission
) {
    User* user = new UserImpl(
        name, email, cpf, password, courses, permission
    );

    this->user_list.push_back(user);

    return user;
}

User *ModelImpl::getUser() const {
    return user;
}

void ModelImpl::setUser(User *value) {
    user = value;
}

vector<User*>& ModelImpl::getUserList() {
    return user_list;
}

void ModelImpl::setUserList(const vector<User*> &value) {
    user_list = value;
}

bool ModelImpl::readUser(const string& file){
    ifstream input_file;
    vector<User*> user_list;

    input_file.open(file, ios::in);

    string name, email, cpf, password, fav_1, fav_2, fav_3, fav_4, fav_5, fav_6, permission;
    vector<string> favorites_aux;
    while(getline(input_file, name, ';')){
        getline(input_file, email, ';');

        getline(input_file, cpf, ';');

        getline(input_file, password, ';');

        getline(input_file, fav_1, ';');
        favorites_aux.push_back(fav_1);

        getline(input_file, fav_2, ';');
        favorites_aux.push_back(fav_2);

        getline(input_file, fav_3, ';');
        favorites_aux.push_back(fav_3);

        getline(input_file, fav_4, ';');
        favorites_aux.push_back(fav_4);

        getline(input_file, fav_5, ';');
        favorites_aux.push_back(fav_5);

        getline(input_file, fav_6, ';');
        favorites_aux.push_back(fav_6);

        getline(input_file, permission);

        vector<bool> favorites;
        for(auto it : favorites_aux){
            if(it == "0")
                favorites.push_back(false);
            else
                favorites.push_back(true);
        }

        User* user = this->createUser(
            name, email, cpf, password, favorites, stoi(permission)
        );
        user_list.push_back(user);
    }

    this->setUserList(user_list);

    input_file.close();

    return input_file.good();
}

bool ModelImpl::writeUser(const string& file){
    ofstream output_file;

    output_file.open(file, ios::out);

    for (auto it : this->user_list) {
        output_file << it->getName() << ";"
                    << it->getEmail() << ";"
                    << it->getCPF() << ";"
                    << it->getPassword() << ";";
        for (auto fav : it->getCourses())
            output_file << fav << ";";

        output_file << it->getPermission() << "\n";
    }

    output_file.close();
    return output_file.good();
}
