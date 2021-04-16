#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include "../classes/course_impl.h"

using namespace std;

/**
 * @brief Derived class where all methods will be implemented according to 
 *        the desired modeling.
 * 
 */
class ModelImpl : public Model {
protected:
    vector<Course*> courses; /**< Model's course sets. */

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
};

#endif // MODEL_IMPL_H
