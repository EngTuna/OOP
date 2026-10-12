#include "Image_Class.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;



// Filter 2: Black and White
void applyBlackAndWhite(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            int val = (avg > 127) ? 255 : 0;
            img(i, j, 0) = img(i, j, 1) = img(i, j, 2) = val;
        }
    }
}



// Filter 6: Rotate Image
Image applyRotate(Image& img, int choice) {
    if (choice == 1) {
        Image rotated(img.height, img.width);
        for (int i = 0; i < img.width; ++i)
            for (int j = 0; j < img.height; ++j)
                for (int c = 0; c < 3; ++c)
                    rotated(img.height - 1 - j, i, c) = img(i, j, c);
        return rotated;
    } else if (choice == 2) {
        Image rotated(img.width, img.height);
        for (int i = 0; i < img.width; ++i)
            for (int j = 0; j < img.height; ++j)
                for (int c = 0; c < 3; ++c)
                    rotated(img.width - 1 - i, img.height - 1 - j, c) = img(i, j, c);
        return rotated;
    } else {
        Image rotated(img.height, img.width);
        for (int i = 0; i < img.width; ++i)
            for (int j = 0; j < img.height; ++j)
                for (int c = 0; c < 3; ++c)
                    rotated(j, img.width - 1 - i, c) = img(i, j, c);
        return rotated;
    }
}



// Filter 10: Edge Detection
void applyEdgeDetection(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            img(i, j, 0) = img(i, j, 1) = img(i, j, 2) = avg;
        }
    }
    Image copyImg = img;
    for (int i = 1; i < img.width - 1; ++i) {
        for (int j = 1; j < img.height - 1; ++j) {
            int gx = abs(copyImg(i + 1, j, 0) - copyImg(i - 1, j, 0));
            int gy = abs(copyImg(i, j + 1, 0) - copyImg(i, j - 1, 0));
            img(i, j, 0) = img(i, j, 1) = img(i, j, 2) = ((gx + gy) > 35) ? 0 : 255;
        }
    }
}



// Filter 14: TV Effect
void applyTVEffect(Image& img) {
    for (int j = 0; j < img.height; ++j) {
        if (j % 3 == 0) {
            for (int i = 0; i < img.width; ++i) {
                img(i, j, 0) *= 0.45;
                img(i, j, 1) *= 0.45;
                img(i, j, 2) *= 0.45;
            }
        }
    }
}
