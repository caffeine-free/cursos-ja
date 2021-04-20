#ifndef REGISTER_IMPL_H
#define REGISTER_IMPL_H

#include "register.h"
#include <regex>

using std::regex;

/**
 * @brief this class represents a register
 *
 */
class RegisterImpl : public Register {
public:
    /**
     * @brief Construct a new Register Impl object
     *
     */
    RegisterImpl();

    /**
     * @brief Destroy the Register Impl object
     *
     */
    ~RegisterImpl();

    /**
     * @brief Create a Register object
     *
     * @return Register* the register pointer
     */
    static Register* createRegister();

    /**
     * @brief register an user
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    bool create(
        Model*, string, string, string, string, const vector<Course*>&, int
    );

    /**
     * @brief remove an user
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    bool remove(Model*, User*);

    /**
     * @brief update an user
     *
     */
    void update(
        Model*, User*, string, string, string, string, const vector<Course*>&, int
    );

    /**
     * @brief search an user
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    bool search(Model*, const string&) const;

    /**
     * @brief consult an user
     *
     * @return User* the user pointer
     */
    User* consult(Model*, const string&) const;

    /**
     * @brief validate the user email
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    bool ValidateEmail(string);


};

#endif // REGISTER_IMPL_H
