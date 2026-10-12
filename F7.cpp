#include "Image_Class.h"
#include <iostream>
#include <string>

using namespace std;

// دالة لتغميق أو تفتيح الصورة
void processImageLight(Image& img, int choice) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < img.channels; ++k) {
                if (choice == 1) {
                    // تفتيح الصورة بنسبة 50%
                    img(i, j, k) = img(i, j, k) + (255 - img(i, j, k)) * 0.5;
                } else if (choice == 2) {
                    // تغميق الصورة بنسبة 50%
                    img(i, j, k) = img(i, j, k) * 0.5;
                }
            }
        }
    }
}

int main() {
    string inputFileName, outputFileName;
    int choice;

    cout << "Enter input image filename: ";
    cin >> inputFileName;

    // تحميل الصورة
    Image img(inputFileName);

    cout << "Choose option:\n1. Lighten Image (50%)\n2. Darken Image (50%)\nEnter choice (1 or 2): ";
    cin >> choice;

    // تطبيق الفلتر حسب اختيار المستخدم
    processImageLight(img, choice);

    cout << "Enter output image filename to save: ";
    cin >> outputFileName;

    // حفظ الصورة
    img.saveImage(outputFileName);

    cout << "Image processed and saved successfully!" << endl;

    return 0;
}