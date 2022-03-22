#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "die.h"


int main(int argc, char **argv){
    srand(time(NULL));

    Die die(6);

    std::cout << "The roll is: " << die.roll() << std::endl;
    
    return 0;
}