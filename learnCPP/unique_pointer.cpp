#include <algorithm>
#include <iostream>
#include <memory>

class myResource {
    public:
        myResource(){std::cout << "Resource Created";}
        ~myResource(){std::cout << "Resource Destroyed";}
};

int main() {
    // Create a unique_ptr of type myResource
    // This is allocated on the stack and will go out of scope at the end of
    // main()
    std::unique_ptr<myResource> res1 { new myResource };
    std::unique_ptr<myResource> res2{}; // starts as nullptr
    
    //Copy semantics are disabled
    //res2 = res1 // This doesn't work

    // This uses move semantics
    res2 = std::move(res1); //res1 is null now

    //implicit cast to bool
    if (res2) { std::cout << "Res2 exists" <<'\n'; }


    // Allocate a resource object and have it owned by multiple shared pointers 
    // You can do these in different scopes, although have to be careful about
    // destructors and going out of scope
    myResource *foo = new myResource;
    std::shared_ptr<myResource> ptr1 {foo};
    std::shared_ptr<myResource> ptr2 {foo};
}
