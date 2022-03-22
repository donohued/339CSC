#include <stdlib.h>
#include "die.h"

Die::Die(int nsides){
    this->nsides = nsides;
}

Die::~Die(){
    
}

int Die::roll(){
    return rand() % this->nsides + 1;
}