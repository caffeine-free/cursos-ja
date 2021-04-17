#ifndef COURSE_IMPL_H
#define COURSE_IMPL_H

#include "course.h"

using namespace std;

/**
 * @brief this represents a course
 *
 */
class CourseImpl : public Course {
protected:
    string name; // Course's name
    string description; // Course's description
    string price; // Course's price
public:
    /**
     * @brief Construct a new Course Impl object
     *
     */
    CourseImpl();

    /**
     * @brief Construct a new Course Impl object
     *
     */
    CourseImpl(Course*);

    /**
     * @brief Construct a new Course Impl object
     *
     */
    CourseImpl(string, string, string);

    /**
     * @brief Destroy the Course Impl object
     *
     */
    ~CourseImpl();

    /**
     * @brief Get the Name object
     *
     * @return string the Course's name
     */
    string getName() const;

    /**
     * @brief Set the Name object
     *
     */
    void setName(const string&);

    /**
     * @brief Get the Description object
     *
     * @return string the Course's description
     */
    string getDescription() const;

    /**
     * @brief Set the Description object
     *
     */
    void setDescription(const string&);

    /**
     * @brief Get the Price object
     *
     * @return string the Course's price
     */
    string getPrice() const;

    /**
     * @brief Set the Price object
     *
     */
    void setPrice(const string&);

    Course& operator=(Course&);

    bool operator==(Course&);
};

#endif // COURSE_IMPL_H
