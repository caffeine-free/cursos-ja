#ifndef REGISTER_H
#define REGISTER_H

#include "model.h"
#include <QMessageBox>

using namespace std;


/**
 * @brief this class represents a register
 *
 */
class Register {
public:
    /**
     * @brief Destroy the Register object
     *
     */
    virtual ~Register() {};

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
    virtual bool create(
        Model*, string, string, string, string, const vector<Course*>&, int
    ) = 0;

    /**
     * @brief remove an user
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    virtual bool remove(Model*, User*) = 0;

    /**
     * @brief update an user
     *
     */
    virtual void update(
        Model*, User*, string, string, string, string, const vector<Course*>&, int
    ) = 0;

    /**
     * @brief search an user
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    virtual bool search(Model*, const string&) const = 0;

    /**
     * @brief consult an user
     *
     * @return User* the user pointer
     */
    virtual User* consult(Model*, const string&) const = 0;

    /**
     * @brief validate the user email
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    virtual bool ValidateEmail(string) = 0;


};

#endif // REGISTER_H
