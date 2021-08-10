#include <iostream>
#include <memory>

class daniel
{
public:
    void show()
    {
        std::cout << "daniel::show()" << std::endl;
    }
};

int main()
{

    /* auto_ptr - not been deprecated from C++11 */
    std::cout << "\nExample of auto_prt" << std::endl;
    std::auto_ptr<daniel> p1(new daniel);
    p1->show();

    std::cout << "Memory address of auto_ptr: " << p1.get() << std::endl;

    // copy constructor --> make p1 empty
    std::auto_ptr<daniel> p2(p1);

    // Allow to assign --> insecure
    /*p1 = p2;
    std::cout << p2.get() << std::endl; */
    std::cout << "\nERROR: ";
    p1->show();
    std::cout << "----> Because already made p1 empty\n"
              << std::endl;
    p2->show();

    if (p1.get() == nullptr)
    {
        std::cout << "Already removed p1 from memory" << std::endl;
    }

    std::cout << p2.get() << std::endl;

    // In case that we assign the value of auto_ptr to a normal ptr
    // the mechanism of auto_ptr did not work in this case
    // Conclusion: They can not be used within STL container due to aforementioned inability to be copied
    std::cout << "\nCorner Case of auto_ptr" << std::endl;
    std::auto_ptr<daniel> p3 = p2;
    std::cout << p2.get() << std::endl;
    std::cout << p3.get() << std::endl;
    std::cout << "\n---------------------------------" << std::endl;

    /* unique_ptr - replacemen for auto_ptr */
    // (-) no fake copy constructor like auto_ptr, new feature (deleter)
    // (+) support for array
    // Prevent copying u1 = u2 with normal assignment
    // Conclusion: The resource will be reclaimed when the unique_ptr is detroyed (can not copied)
    std::cout << "Example of unique_prt" << std::endl;
    std::unique_ptr<daniel> u1(new daniel);
    std::cout << "Address of u1: " << u1.get() << std::endl;
    u1->show();

    // There is only one unique_ptr to any resource, any attempt to make a copy will cause compile error
    // While auto_ptr make a fake copy, assign the address and make lvalue empty --> insercure
    // std::unique_ptr<daniel> u2 = u1; ---> ERROR
    std::unique_ptr<daniel> u2 = std::move(u1); // Transfer ownership
    std::cout << "Address of u1: " << u1.get() << std::endl;
    std::cout << "Address of u2: " << u2.get() << std::endl;
    u2->show();
    u1->show(); // ????
    //
    std::cout << "\n---------------------------------" << std::endl;

    /* shared_ptr: container for raw pointer - reference counting ownership model */
    std::shared_ptr<daniel> s1(new daniel);
    std::cout << "Address of s1: " << s1.get() << std::endl;
    s1->show();
    std::shared_ptr<daniel> s2(s1);
    std::cout << "Address of s1: " << s1.get() << std::endl;
    std::cout << "Address of s2: " << s2.get() << std::endl;
    s2->show();

    // Return the number of shared_ptr referring to the same object
    std::cout << "The number of shared_ptr when search by s1: " << s1.use_count() << std::endl;
    std::cout << "The number of shared_ptr when search by s2: " << s2.use_count() << std::endl;

    // Take back the ownership of s1
    s1.reset();
    std::cout << "\n-----------After removing s1--------------" << std::endl;
    std::cout << "The number of shared_ptr when search by s1: " << s1.use_count() << std::endl;
    std::cout << "The number of shared_ptr when search by s2: " << s2.use_count() << std::endl;
    std::cout << "Address of s1: " << s1.get() << std::endl;
    std::cout << "Address of s2: " << s2.get() << std::endl;

    /* */

    return 0;
}