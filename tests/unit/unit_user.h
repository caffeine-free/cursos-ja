#ifndef UNIT_COURSE_H
#define UNIT_COURSE_H

#include <assert.h>
#include "./src/classes/user_impl.h"
#include "./src/classes/course_impl.h"

/**
 * @brief Tests class constructors.
 *
 */
void unit_user_constructor();

/**
 * @brief Tests class destructors.
 *
 */
void unit_user_destructor();

/**
 * @brief Tests getName method.
 *
 */
void unit_user_getName();

/**
 * @brief Tests setName method.
 *
 */
void unit_user_setName();

/**
 * @brief Tests getEmail method.
 *
 */
void unit_user_getEmail();

/**
 * @brief Tests setEmail method.
 *
 */
void unit_user_setEmail();

/**
 * @brief Tests getCPF method.
 *
 */
void unit_user_getCPF();

/**
 * @brief Tests setCPF method.
 *
 */
void unit_user_setCPF();

/**
 * @brief Tests getPassword method.
 *
 */
void unit_user_getPassword();

/**
 * @brief Tests setPassword method.
 *
 */
void unit_user_setPassword();

/**
 * @brief Tests getPermission method.
 *
 */
void unit_user_getPermission();

/**
 * @brief Tests setPermission method.
 *
 */
void unit_user_setPermission();

/**
 * @brief Tests the assignment operator overload.
 *
 */
void unit_user_assignment();

/**
 * @brief Runs all unit tests of the User class.
 *
 */
void run_unit_tests_user();

#endif // UNIT_COURSE_H
