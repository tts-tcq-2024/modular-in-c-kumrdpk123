#include <stdio.h>
#include <assert.h>
#include "colorPair.h"

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int MAX_COLORPAIR_NAME_CHARS = 16;
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

void printColorCodeReferenceManual(int numberOfMajorColors, int numberOfMinorColors) {
    int majorColorIterator, minorColorIterator;
    int pairNumber = 1;

    printf("25 PAIR COLOR CODE REFERENCE MANUAL\n");
    printf("----------------------------------------\n");
    printf("| PAIR NO. | MAJOR COLOR | MINOR COLOR |\n");
    printf("----------------------------------------\n");

    for (majorColorIterator = 0; majorColorIterator < numberOfMajorColors; majorColorIterator++) {
        for (minorColorIterator = 0; minorColorIterator < numberOfMinorColors; minorColorIterator++) {
            printf("|   %d | %s | %s |\n", pairNumber++, MajorColorNames[majorColorIterator], MinorColorNames[minorColorIterator]);
        }
        printf("----------------------------------------\n");
    }
}

// Gets the pair number from a ColorPair
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}
