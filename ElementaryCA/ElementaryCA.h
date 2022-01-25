//
// Created by alexe on 08.10.2021.
//

#ifndef CELLAUTOMATA_ELEMENTARYCA_H
#define CELLAUTOMATA_ELEMENTARYCA_H

#include <vector>
#include <cstdint>


union Byte{
    uint8_t AllBits;
    struct Bits{
        uint8_t B1:1;
        uint8_t B2:1;
        uint8_t B3:1;
        uint8_t B4:1;
        uint8_t B5:1;
        uint8_t B6:1;
        uint8_t B7:1;
        uint8_t B8:1;
    } b;
};


struct neighborhood{
    uint8_t b:3;
};


class ElementaryCA{
 private:
    std::vector<uint8_t> currentState; // char but can be only 0 or 1


 public:
    void updateState(uint8_t ruleNr);
    void vizualize();
    explicit ElementaryCA(uint32_t len);

};
#endif //CELLAUTOMATA_ELEMENTARYCA_H
