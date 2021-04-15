#include "client_impl.h"

ClientImpl::ClientImpl() {}

ClientImpl::ClientImpl(Client* Client) {
    this->name = Client->getName();
    this->email = Client->getEmail();
    this->cpf = Client->getCPF();
    this->password = Client->getPassword();
}

ClientImpl::ClientImpl(
    string name,
    string email,
    string cpf,
    string password
) {
    this->name = name;
    this->email = email;
    this->cpf = cpf;
    this->password = password;
}

ClientImpl::~ClientImpl() {}

string ClientImpl::getName() const {
    return this->name;
}

void ClientImpl::setName(const string& name) {
    this->name = name;
}

string ClientImpl::getEmail() const {
    return this->email;
}

void ClientImpl::setEmail(const string& email) {
    this->email = email;
}

string ClientImpl::getCPF() const {
    return this->cpf;
}

void ClientImpl::setCPF(const string& cpf) {
    this->cpf = cpf;
}

string ClientImpl::getPassword() const {
    return this->password;
}

void ClientImpl::setPassword(const string& password) {
    this->password = password;
}
