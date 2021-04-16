#ifndef MODEL_H
#define MODEL_H

#include "../classes/course.h"
#include "../classes/user.h"

/**
 * @brief The Model class
 */
class Model {
public:
    /**
     * @brief Destroy the Model object.
     */
    virtual ~Model() {};

    /**
     * @brief Create a Model object.
     * @return Model* Model set.
     */
    static Model* createModel();

    /**
     * @brief Create a Course object
     *
     * @return Course* Course set.
     */
    virtual Course* createCourse(string, string, string) = 0;

    /**
     * @brief Remove a Course object
     *
     * @return true if it was successful
     * @return false if it failed
     */
    virtual bool removeCourse(Course*) = 0;

    /**
     * @brief Update a Course object
     *
     */
    virtual void updateCourse(Course*, string, string, string) = 0;

    /**
     * @brief Get the Courses object
     *
     * @return vector<Course*>& Courses set
     */
    virtual vector<Course*>& getCourses() = 0;

    /**
     * @brief Set the Courses object
     *
     */
    virtual void setCourses(const vector<Course*> &) = 0;

    /**
     * @brief Adds a course to the model.
     *
     */
    virtual void add(Course*) = 0;

    virtual User* createUser(string, string, string, string, const vector<Course*>&, int) = 0;

    virtual bool removeUser(User*) = 0;

    virtual void updateUser(User*, string, string, string) = 0;

    virtual User* getUser() const = 0;

    virtual vector<User*>& getUserList() = 0;

    virtual void setUser(User*) = 0;

    virtual void setUserList(const vector<User*> &) = 0;

    
};

#endif // MODEL_H
