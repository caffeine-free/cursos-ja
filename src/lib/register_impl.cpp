#include "register.impl.h"

#include <iostream>
using namespace std;

RegisterImpl::RegisterImpl() {}

RegisterImpl::~RegisterImpl() {}

Register* Register::createRegister() {
    return RegisterImpl::createRegister();
}

Register* RegisterImpl::createRegister() {
    return new RegisterImpl();
}

bool RegisterImpl::create(
    Model* model,
    string name,
    string email,
    string cpf,
    string password,
    const vector<bool>& courses,
    int permission
)
 {
    User* user = model->createUser(
        name, email, cpf, password, courses, permission
    );
    model->setUser(user);
    //Criar cliente no banco
    //return model->writeUser("../series-feelings/database/user-list.csv");
}

bool RegisterImpl::remove(Model* model, User* user) {
    if(!this->search(model, user->getEmail()))
        return false;
    else{
        model->getUserList().erase(
            std::remove(
                model->getUserList().begin(),
                model->getUserList().end(), user
            ),
            model->getUserList().end()
        );
        model->setUser(nullptr);


        //deletar cliente no banco
        //return model->writeUser("../series-feelings/database/user-list.csv");
    }
}

void RegisterImpl::update(
    Model* model,
    User* user,
    string name,
    string email,
    string cpf,
    string password,
    const vector<bool>& courses,
    int permission
) {
    user->setName(name);
    user->setEmail(email);
    user->setCPF(cpf);
    user->setPassword(password);
    user->setCourses(courses);
    //Atualizar no banco
    //model->writeUser("../series-feelings/database/user-list.csv");
}

bool RegisterImpl::search(Model* model, const string& name) const {
    for(auto it : model->getUserList())
        if(it->getName() == name)
            return true;

    return false;
}

User* RegisterImpl::consult(Model* model, const string& name) const { //Talvez não seja necessário
    for(auto it : model->getUserList())
        if(it->getName() == name)
            return it;

    return nullptr;
}

bool RegisterImpl::ValidateEmail(string email) {
    if (regex_match(email, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)")))
        return true;

    return false;
}

