#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * @brief this class represents an user
 *
 */
class User {
public:
    /**
     * @brief Destroy the User object
     *
     */
    virtual ~User() {};

    /**
     * @brief Get the Name object
     *
     * @return string the user name
     */
    virtual string getName() const = 0;

    /**
     * @brief Set the Name object
     *
     */
    virtual void setName(const string &) = 0;

    /**
     * @brief Get the Email object
     *
     * @return string the user email
     */
    virtual string getEmail() const = 0;

    /**
     * @brief Set the Email object
     *
     */
    virtual void setEmail(const string &) = 0;

    /**
     * @brief Get the Birth object
     *
     * @return string the user birthday
     */
    virtual string getCPF() const = 0;

    /**
     * @brief Set the Birth object
     *
     */
    virtual void setCPF(const string &) = 0;

    /**
     * @brief Get the Password object
     *
     * @return string the user password
     */
    virtual string getPassword() const = 0;

    /**
     * @brief Set the Password object
     *
     */
    virtual void setPassword(const string &) = 0;

    /**
     * @brief Get the Courses object
     *
     * @return vector<bool>& the user courses
     */
    virtual vector<bool>& getCourses() = 0;

    /**
     * @brief Set the Courses object
     *
     */
    virtual void setCourses(const vector<bool> &) = 0;

    /**
     * @brief Get the Permission object
     *
     * @return int the user permission level
     */
    virtual int getPermission() const = 0;

    /**
     * @brief Set the Permission object
     *
     */
    virtual void setPermission(int) = 0;

    /**
     * @brief assignment operator
     *
     * @return User& the user reference
     */
    virtual User& operator=(User&) = 0;

    /**
     * @brief association operator
     *
     * @return true  if it was successful
     * @return false if it failed
     */
    virtual bool operator==(User&) = 0;
};

#endif // USER_H
