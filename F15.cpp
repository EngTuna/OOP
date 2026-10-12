#include <iostream>
#include "Image_Class.h"

using namespace std;

void applyPurpleFilter(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            int r = image(i, j, 0);
            int g = image(i, j, 1);
            int b = image(i, j, 2);

            g = g * 0.5;

            r = r + (255 - r) * 0.2;
            b = b + (255 - b) * 0.2;

            image(i, j, 0) = r;
            image(i, j, 1) = g;
            image(i, j, 2) = b;
        }
    }

    cout << "Purple filter applied successfully!\n";
}