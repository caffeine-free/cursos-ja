#ifndef CLIENT_IMPL_H
#define CLIENT_IMPL_H

#include "user.h"

using namespace std;

/**
 * @brief Derivation of class Client, where is the implementation of the methods
 *
 */
class ClientImpl : public Client {
protected:
    string name; // Client's name
    string email; // Client's email
    string cpf; // Client's CPF
    string password; // Client's password
public:
    /**
     * @brief Construct a new Client Impl object
     *
     */
    ClientImpl();

    /**
     * @brief Construct a new Client Impl object
     *
     */
    ClientImpl(Client*);

    /**
     * @brief Construct a new Client Impl object
     *
     */
    ClientImpl(string, string, string, string);

    /**
     * @brief Destroy the Client Impl object
     *
     */
    ~ClientImpl();

    /**
     * @brief Get the Name object
     *
     * @return string the Client's name
     */
    string getName() const;

    /**
     * @brief Set the Name object
     *
     */
    void setName(const string&);

    /**
     * @brief Get the Email object
     *
     * @return string the Client's email
     */
    virtual string getEmail() const = 0;

    /**
     * @brief Set the Email object
     *
     */
    virtual void setEmail(const string&) = 0;

    /**
     * @brief Get the CPF object
     *
     * @return string the Client's CPF
     */
    virtual string getCPF() const = 0;

    /**
     * @brief Set the CPF object
     *
     */
    virtual void setCPF(const string&) = 0;

    /**
     * @brief Get the Password object
     *
     * @return string the Client's password
     */
    virtual string getPassword() const = 0;

    /**
     * @brief Set the Password object
     *
     */
    virtual void setPassword(const string&) = 0;
};

#endif // CLIENT_H
