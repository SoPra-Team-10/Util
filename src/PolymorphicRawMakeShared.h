/**
 * @file PolymorphicRawMakeShared.h
 * @author paulnykiel
 * @date 17.07.19
 * Description here TODO
 */

#ifndef SOPRAUTIL_POLYMORPHICRAWMAKESHARED_H
#define SOPRAUTIL_POLYMORPHICRAWMAKESHARED_H

namespace util {
    /**
     * Tries to convert a raw pointer to a shared_ptr by copying its value. This requires us to know the
     * actual type if the class is polymorphic
     * @tparam Base the polymorphic class of which the pointer is
     * @tparam FirstChild the first possible child class
     * @tparam Childs all other possible child classes
     * @param base the pointer to the polymorphic class
     * @return a shared_ptr of type Base with the contents of base copied into them
     * @throws std::runtime_error if the pointer cannot be converted to any of the child classes
     */
    template<typename Base, typename FirstChild, typename ...Childs>
    auto makeSharedFromRaw(const Base *base) -> std::shared_ptr <Base> {
        const auto *firstChild = dynamic_cast<const FirstChild *>(base);
        if (firstChild) {
            return std::make_shared<FirstChild>(*firstChild);
        } else {
            makeSharedFromRaw<Base, Childs...>(base);
        }
    }

    /**
     * Base for the recursion, the pointer cannot be converted to any of the child classes.
     * @throws std::runtime_error because this is the base case
     */
    template<typename Base>
    auto makeSharedFromRaw(const Base*) -> std::shared_ptr <Base> {
        throw std::runtime_error{"Pointer cannot be converted to any of the child classes!"};
    }
}

#endif //SOPRAUTIL_POLYMORPHICRAWMAKESHARED_H
