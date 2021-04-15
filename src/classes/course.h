#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief this class represents a course
 *
 */
class Course {
public:
    /**
     * @brief Destroy the Course object
     *
     */
    virtual ~Course() {};

    /**
     * @brief Get the Name object
     *
     * @return string the Course's name
     */
    virtual string getName() const = 0;

    /**
     * @brief Set the Name object
     *
     */
    virtual void setName(const string&) = 0;

    /**
     * @brief Get the Description object
     *
     * @return string the Course's description
     */
    virtual string getDescription() const = 0;

    /**
     * @brief Set the Description object
     *
     */
    virtual void setDescription(const string&) = 0;

    /**
     * @brief Get the Price object
     *
     * @return string the Course's price
     */
    virtual string getPrice() const = 0;

    /**
     * @brief Set the Price object
     *
     */
    virtual void setPrice(const string&) = 0;
};

#endif // COURSE_H
