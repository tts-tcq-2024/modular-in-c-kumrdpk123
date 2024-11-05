#include <stdio.h>
#include <assert.h>
#include "colorPair.h"
#include "color_pair_test.c"

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    printColorCodeReferenceManual(numberOfMajorColors,numberOfMinorColors);
    return 0;
}
