#include <iostream>
#include "ElementaryCA.h"




int main(int argc, char** argv){
    ElementaryCA ca(200);
    uint8_t ruleNr = atoi(argv[1]);

    for(uint32_t i = 0; i < 200 ; i++){
//        std::cout << "ASDAS\n";
        ca.vizualize();
        ca.updateState(ruleNr);
    }

}
