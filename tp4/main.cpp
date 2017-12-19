
#include "Vector.h"

int main (int argc, char ** argv) {
    
    Vector v;
    
    v.add ("1");
    v.add ("2");
    v.add ("3");
    
    std::cout << v.toString() << std::endl;
    
    return 0;
}