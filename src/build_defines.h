/**
 * @file build_defines.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief This is where it's defined if the build is for the microcontroller or if it's for testing.
 *        If TEST_BUILD is defined, it enables the different options of debugging with iostream.
 *        If DEBUGGING_SUBTLE is defined, only the most important couts are implemented (used for specific testing).
 *        If DEBUGGING_LARGE is defined, a lot of extra couts are implemented in the test files (used for large scale cout testing).
 * @version 0.1
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */


/**
 * @brief This define should be here if the code should compile for a microcontroller.
 *        This outcomments ALL #include <iostream> and ALL calls to functions in iostream.
 *        By commenting this line, DEBUGGING_SUBTLE is automatically defined.
 */
// #define TEST_BUILD

/**
 * @brief This define should be here if the code should compile for testing with debugging for console.
 *        OBS!!! It can only be defined if TEST_BUILD is defined (outcommented)!!!
 */
#ifdef TEST_BUILD
    #define DEBUGGING_SUBTLE
#endif // TEST_BUILD

/**
 * @brief This define implements a LOT of cout for a LOT of objects and methods to really get into knowing what
 *        methods are called.
 *        OBS! Can only be defined if TEST_BUILD is defined AND DEBUGGING_SUBTLE is defined!
 */
#ifdef TEST_BUILD
    #ifdef DEBUGGING_SUBTLE
        // #define DEBUGGING_LARGE
    #endif // DEBUGGING_SUBTLE
#endif // TEST_BUILD