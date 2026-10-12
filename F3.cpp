#include "Image_Class.h"
#include <iostream>
#include <string>

using namespace std;

// دالة عكس ألوان الصورة (Invert)
void invertImage(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < img.channels; ++k) {
                // عكس قيمة كل بكسل
                img(i, j, k) = 255 - img(i, j, k);
            }
        }
    }
}

int main() {
    string inputFileName, outputFileName;

    cout << "Enter input image filename: ";
    cin >> inputFileName;

    // تحميل الصورة
    Image img(inputFileName);

    // تطبيق الفلتر
    invertImage(img);

    cout << "Enter output image filename to save: ";
    cin >> outputFileName;

    // حفظ الصورة
    img.saveImage(outputFileName);

    cout << "Image inverted and saved successfully!" << endl;

    return 0;
}