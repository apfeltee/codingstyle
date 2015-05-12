
/*
In C++, C++ standard library headers come before *any other header*.
Additionally, C standard library headers should use the prefixed version -
i.e., <cstdio> instead of <stdio.h>, <cstring> instead of <string.h>, <cctype> instead of <ctype.h>, etc.
Platform-dependant headers go last, unless compiler/platform-specific behaviour dictates otherwise, in
which case you should add a comment to explain why.
*/
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <cctype>

/*
* always indent the preprocessor; but indent *with* the hash, not within the hash.
* prefer to use defined() over #ifdef/#ifndef.
*/
#if defined(__unix__) || defined(__CYGWIN32__)
    #include <unistd.h>
#elif defined(_WIN32)
    #include <io.h>
#endif

/*
Global and static functions should always be CamelCased, and namespaced (if possible).
*/
namespace Foo
{
    /*
    * always prefer doxygen comments for documentation, unless you have a ***very*** good reason not to.
    * Doxygen is supported on a myriad of platforms!
    * for parameters, prefer commenting variable names directly.
    */
    /**
    * Does a Bar thing.
    */
    void DoBarThing(
        /// The something thing that does the thing.
        int something
    );
}

/*
unless the class directly extends functionality of the C++ standard library, class names should always be CamelCased.
treat access specifiers as indentation indicators; that is, indent after a block.
*/
class PersonThing
{
    /*
    * make use of access specifiers to denote how class members are used, and add comments *after* the specifier
    * to summarize usage.
    */

    /*
    * prefer to make types declared in classes/structs public, unless you have a reason not to, such
    * as race conditions (due to inheritance, etc. which is unlikely...). 
    */
    public: // types
        /*
        * if you already use C++11 features, go *all the way*! that includes using the 'using X = Y' notation,
        * instead of typedefs.
        */
        using HobbyList = std::vector<std::string>;

    private: // variables
        /*
        * private variables should *always* be prefixed with 'm_', and be lowercase.
        * use descriptive names; don't abbreviate in pointless ways, but don't overdo it either.
        */
        HobbyList m_hobbies;

    public: // functions
        PersonThing()
        {
        }
};
