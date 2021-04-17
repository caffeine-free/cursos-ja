#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include <fstream>
#include <sstream>

#include "model.h"
#include "../classes/course_impl.h"
#include "../classes/user_impl.h"

using namespace std;

/**
 * @brief Derived class where all methods will be implemented according to 
 *        the desired modeling.
 * 
 */
class ModelImpl : public Model {
protected:
    vector<Course*> courses; /**< Model's course sets. */
    vector<User*> users;    /**< Model's stored users. */
    User* user;             /**< Model's logged user. */
public:
    /**
     * @brief Construct a new Model Impl object
     * 
     */
    ModelImpl();

    /**
     * @brief Destroy the Model Impl object
     * 
     */
    ~ModelImpl();

    /**
     * @brief Create a Model object
     * 
     * @return Model* Model set
     */
    static Model* createModel();

    /**
     * @brief Create a Course object
     * 
     * @return Course* Course set
     */
    Course* createCourse(string, string, string);

    /**
     * @brief Remove a Course object
     * 
     * @return true if it was successful
     * @return false if it failed
     */
    bool removeCourse(Course*);

    /**
     * @brief Update a Course object
     * 
     */
    void updateCourse(Course*, string, string, string);

    /**
     * @brief Get the Courses object
     * 
     * @return vector<Course*>& Courses set
     */
    vector<Course*>& getCourses();

    /**
     * @brief Set the Courses object
     * 
     */
    void setCourses(const vector<Course*> &);

    /**
     * @brief Adds a course to the model.
     * 
     */
    void add(Course*);

    /**
     * @brief Create a User object
     * 
     * @return User* User set
     */
    User* createUser(string, string, string, string, const vector<Course*>&, int);

    /**
     * @brief Get the User object
     * 
     * @return User* User set
     */
    User* getUser() const;

    /**
     * @brief Set the User object
     * 
     */
    void setUser(User*);

    /**
     * @brief Get the User List object
     * 
     * @return vector<User*>& Users set
     */
    vector<User*>& getUserList();

    /**
     * @brief Set the User List object
     * 
     */
    void setUserList(const vector<User*> &);

    /**
     * @brief Remove a Course object
     * 
     * @return true if it was successful
     * @return false if it failed
     */
    bool removeUser(User*);

    /**
     * @brief Update a Course object
     * 
     */
    void updateUser(User*, string, string, string);

    bool writeCourse(const string&);

    bool readCourse(const string&);

    /**
     * @brief Write a file
     * 
     * @return true if it was successful
     * @return false if it failed
     */
    bool writeUser(const string&);

    /**
     * @brief Read a file
     * 
     * @return true if it was successful
     * @return false if it failed
     */
    bool readUser(const string&);

};

#endif // MODEL_IMPL_H
