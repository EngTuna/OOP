#include <iostream>
#include "Image_Class.h"

using namespace std;

// ===================================================
// الفلتر رقم 11: قص الصورة (Crop Image)
// الفكرة: بناخد إحداثيات نقطة البداية (x, y) والأبعاد المطلوبة (العرض والارتفاع)
// وبنعمل صورة جديدة بالحجم ده وننسخ فيها البكسلات المطلوبة بس.
// ===================================================
void cropImage(Image& image) {
    int x, y, w, h;

    // 1. أخذ نقطة البداية (الزاوية العليا اليسرى)
    cout << "Enter starting point (x y): ";
    cin >> x >> y;

    // 2. أخذ العرض والارتفاع للجزء المراد قصّه
    cout << "Enter width and height to crop (w h): ";
    cin >> w >> h;

    // 3. التأكد إن الإحداثيات والأبعاد صحيحة ومش طالعة بره حدود الصورة الأصلية
    if (x < 0 || y < 0 || x + w > image.width || y + h > image.height || w <= 0 || h <= 0) {
        cout << "Invalid crop dimensions! Out of image bounds.\n";
        return;
    }

    // 4. إنشاء صورة جديدة بالأبعاد المقصوصة (العرض w والارتفاع h)
    Image croppedImage(w, h);

    // 5. نسخ البكسلات من المنطقة المحددة في الصورة الأصلية للصورة الجديدة
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) { // k هي قنوات الألوان الثلاثة (R=0, G=1, B=2)
                croppedImage(i, j, k) = image(x + i, y + j, k);
            }
        }
    }

    // 6. استبدال الصورة الأصلية بالصورة المقصوصة الجديدة
    image = croppedImage;
    cout << "Image cropped successfully!\n";
}