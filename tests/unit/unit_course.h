#ifndef UNIT_COURSE_H
#define UNIT_COURSE_H

#include <assert.h>
#include "./src/classes/course_impl.h"

/**
 * @brief Tests class constructors.
 *
 */
void unit_course_constructor();

/**
 * @brief Tests class destructors.
 *
 */
void unit_course_destructor();

/**
 * @brief Tests getName method.
 *
 */
void unit_course_getName();

/**
 * @brief Tests setName method.
 *
 */
void unit_course_setName();

/**
 * @brief Tests getDescription method.
 *
 */
void unit_course_getDescription();

/**
 * @brief Tests setDescription method.
 *
 */
void unit_course_setDescription();

/**
 * @brief Tests getPrice method.
 *
 */
void unit_course_getPrice();

/**
 * @brief Tests setPrice method.
 *
 */
void unit_course_setPrice();

/**
 * @brief Tests the assignment operator overload.
 *
 */
void unit_course_assignment();

/**
 * @brief Runs all unit tests of the Course class.
 *
 */
void run_unit_tests_course();

#endif // UNIT_COURSE_H
