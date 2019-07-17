/**
 * @file AtDestruction.h
 * @author paulnykiel
 * @date 16.07.19
 * Defines the AtDestructionClass
 */

#ifndef SOPRAUTIL_ATDESTRUCTION_H
#define SOPRAUTIL_ATDESTRUCTION_H

#include <functional>

namespace util {

    /**
     * Provides a wrapper for any class to attach a custom function to the destructor.
     * The class still behaves like the object it wraps.
     * @tparam T the object to wrap
     */
    template <typename T>
    class AtDestruction {
    public:
        /**
         * The type of the wrapped object
         */
        using element_type = T;

        /**
         * Constructor, constructs the underlying type and attaches a function
         * @tparam F the type of the function
         * @tparam Args the type of all arguments that get forwarded to the constructor of the wrapped object
         * @param f the function that gets attached
         * @param args the constructor arguments of the underlying object
         */
        template <typename F, typename ...Args>
        explicit AtDestruction(F &&f, Args&&... args)
            : t{std::forward<Args>(args)...}, atDestruction{std::forward<F>(f)} {}

        /**
         * Default copy ctor, defined to follow the rule of five
         */
        AtDestruction(const AtDestruction&) = default;

        /**
         * Default move ctor, defined to follow the rule of five
         */
        AtDestruction(AtDestruction&&) = default;

        /**
         * Default copy assignment, defined to follow the rule of five
         */
        AtDestruction &operator=(const AtDestruction&) = default;

        /**
         * Default move assignment, defined to follow the rule of five
         */
        AtDestruction &operator=(AtDestruction&&) = default;

        /**
         * Implicitly get the underlying type
         * @return a reference to the underlying type
         */
        operator T&() {
            return t;
        }

        /**
         * DTor call the attached function.
         */
        ~AtDestruction() {
            atDestruction();
        }

        T t;
    private:
        std::function<void(void)> atDestruction;
    };
}

#endif //SOPRAUTIL_ATDESTRUCTION_H
