#ifndef MODEL_H
#define MODEL_H

#include "../classes/course.h"

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
    virtual void add(Course*);
};

#endif // MODEL_H
