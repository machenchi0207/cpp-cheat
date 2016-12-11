/*
Simple rule: always use C++11 enum class, never the old C-style enums.

- http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
- http://stackoverflow.com/questions/4506750/how-do-i-use-the-enum-value-from-a-class-in-another-part-of-code
- http://stackoverflow.com/questions/10869790/best-practices-for-enum-in-c
*/

#include "common.hpp"

int main() {
    // Unlike C, already does typedef, no need to write enum all the time.
    {
        enum E {A, B, C};
        E e = A;
    }

#if __cplusplus >= 201103L
    // Set storage size.
    {
        enum E : char {A, B, C};
        assert(sizeof(E) == sizeof(char));
    }

    // # class enum
    enum class ClassEnum {
        A,
        B
    };

    // Error. YES, namespaces!
    //ClassEnum classEnum = A;

    ClassEnum classEnum = ClassEnum::A;

    // No conversion insanity.
    //int i = ClassEnum::A;
#endif
}
