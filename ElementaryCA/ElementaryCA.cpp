//
// Created by alexe on 08.10.2021.
//

#include "ElementaryCA.h"

#include <iostream>
void ElementaryCA::vizualize() {

    for(auto i : currentState){

        if(i == 0)
            std::cout << ".";
        else
            std::cout << "0";
    }
    std::cout << std::endl;
}

void ElementaryCA::updateState(uint8_t ruleNr) {

    std::vector<uint8_t> newState = currentState;

    Byte rule;
    rule.AllBits = ruleNr;

    for(int i = 1; i <  currentState.size()-1; ++i){
        neighborhood n;
        n.b = 4 * currentState[i-1] + 2 * currentState[i] + currentState[i+1];

        switch (n.b) {
            case 0:
                newState[i] = rule.b.B1;
                break;
            case 1:
                newState[i] = rule.b.B2;
                break;
            case 2:
                newState[i] = rule.b.B3;
                break;
            case 3:
                newState[i] = rule.b.B4;
                break;
            case 4:
                newState[i] = rule.b.B5;
                break;
            case 5:
                newState[i] = rule.b.B6;
                break;
            case 6:
                newState[i] = rule.b.B7;
                break;
            case 7:
                newState[i] = rule.b.B8;
                break;
        }
    }
    currentState = newState;
}

ElementaryCA::ElementaryCA(uint32_t len):
currentState(len){
    currentState[len/2] = 1;
}





