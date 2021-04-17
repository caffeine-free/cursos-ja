#ifndef USER_IMPL_H
#define USER_IMPL_H

#include "user.h"

/**
 * @brief this class represents an user
 *
 */
class UserImpl : public User {
protected:
    string name;                /**< the user name. */
    string email;               /**< the user email. */
    string cpf;               /**< the user cpf. */
    string password;            /**< the user password. */
    vector<Course*> courses;     /**< the user courses. */
    int permission;             /**< the user permission. */

public:
    /**
     * @brief Construct a new User Impl object
     *
     */
    UserImpl();

    /**
     * @brief Construct a new User Impl object
     *
     */
    UserImpl(User*);

    /**
     * @brief Construct a new User Impl object
     *
     */
    UserImpl(string, string, string, string, const vector<Course*>&, int);

    /**
     * @brief Destroy the User Impl object
     *
     */
    ~UserImpl();

    /**
     * @brief Get the Name object
     *
     * @return string the user name
     */
    string getName() const;

    /**
     * @brief Set the Name object
     *
     */
    void setName(const string &);

    /**
     * @brief Get the Email object
     *
     * @return string the user email
     */
    string getEmail() const;

    /**
     * @brief Set the Email object
     *
     */
    void setEmail(const string &);

    /**
     * @brief Get the CPF object
     *
     * @return string the user CPF
     */
    string getCPF() const;

    /**
     * @brief Set the CPF object
     *
     */
    void setCPF(const string &);

    /**
     * @brief Get the Password object
     *
     * @return string the user password
     */
    string getPassword() const;

    /**
     * @brief Set the Password object
     *
     */
    void setPassword(const string &);

    /**
     * @brief Get the Courses object
     *
     * @return vector<bool>& the user courses
     */
    vector<Course*>& getCourses();

    /**
     * @brief Set the Courses object
     *
     */
    void setCourses(const vector<Course*> &);

    /**
     * @brief Get the Permission object
     *
     * @return int the user permission level
     */
    int getPermission() const;

    /**
     * @brief Set the Permission object
     *
     */
    void setPermission(int);

    /**
     * @brief assignment operator
     *
     * @return User& User reference
     */
    User& operator=(User&);

    /**
     * @brief association operator
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    bool operator==(User&);
};

#endif // USER_IMPL_H
