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

    User* createUser(string, string, string, string, const vector<Course*>&, int);

    User* getUser() const;

    void setUser(User *value);

    vector<User*>& getUserList();

    void setUserList(const vector<User*> &);

    bool removeUser(User*);

    void updateUser(User*, string, string, string);

};

#endif // MODEL_IMPL_H
