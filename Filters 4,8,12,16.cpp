#include <iostream>
using namespace std;
#include "Image_Class.h"


//filter 4 (Resize_image) :
Image Resize_image(Image image) {
	int new_w, new_h;
	cout << "enter new width and height : ";
	cin >> new_w >> new_h;

	Image resized_image(new_w, new_h);
	for (int i = 0;i < new_w;++i) {
		for (int j = 0;j < new_h;++j) {

			int old_i = i * image.width / new_w;
			int old_j = j * image.height / new_h;

			for (int c = 0;c < 3;++c) {

				resized_image(i, j, c) = image(old_i, old_j, c);
			}
		}
	}

	return resized_image;

}



//filter 8 (Adding_a_Frame_to_the_Picture) :
Image Adding_a_Frame_to_the_Picture(Image image) {
    int frame_size = 0;
    short frame_type = 0, frame_color = 0;


    while (true) {
        cout << "enter frame type (1)-> simple frame - (2)-> fancy frame \n";
        cin >> frame_type;

        if (frame_type == 1 || frame_type == 2) {
            break;
        }
        cout << "Invalid choice! Please try again.\n";
    }

    while (true) {
        cout << "choose frame color\n";
        cout << "1->Red - 2->Blue - 3->Green - 4->white - 5->Black - 6->Gold - 7->Silver " << endl;
        cin >> frame_color;


        if (frame_color >= 1 && frame_color <= 7) { break; }
        cout << "Invalid choice! Please try again.\n";
    }


    unsigned char frame_R = 0, frame_G = 0, frame_B = 0;

    if (frame_color == 1) { frame_R = 255; frame_G = 0;   frame_B = 0; }
    else if (frame_color == 2) { frame_R = 0;   frame_G = 0;   frame_B = 255; }
    else if (frame_color == 3) { frame_R = 0;   frame_G = 255; frame_B = 0; }
    else if (frame_color == 4) { frame_R = 255; frame_G = 255; frame_B = 255; }
    else if (frame_color == 5) { frame_R = 0;   frame_G = 0;   frame_B = 0; }
    else if (frame_color == 6) { frame_R = 255; frame_G = 215; frame_B = 0; }
    else if (frame_color == 7) { frame_R = 192; frame_G = 192; frame_B = 192; }


    if (frame_type == 1) {
        cout << "enter frame_size : ";
        cin >> frame_size;

        for (int i = 0;i < image.width;++i) {
            for (int j = 0;j < image.height;++j) {

                if (i < frame_size || i >= image.width - frame_size ||
                    j < frame_size || j >= image.height - frame_size) {

                    image(i, j, 0) = frame_R;
                    image(i, j, 1) = frame_G;
                    image(i, j, 2) = frame_B;
                }
            }
        }
    }



    else if (frame_type == 2) {
        int frame2_size = 20, start_line = 10, end_line = 20, inner_frame_color = 0;


        while (true) {
            cout << "choose inner frame color\n";
            cout << "1->Red - 2->Blue - 3->Green - 4->white - 5->Black - 6->Gold - 7->Silver " << endl;
            cin >> inner_frame_color;

            if (inner_frame_color >= 1 && inner_frame_color <= 7) { break; }
            cout << "Invalid choice! Please try again.\n";
        }


        unsigned char inner_frame_r = 0, inner_frame_g = 0, inner_frame_b = 0;

        if (inner_frame_color == 1) { inner_frame_r = 255; inner_frame_g = 0;   inner_frame_b = 0; }
        else if (inner_frame_color == 2) { inner_frame_r = 0;   inner_frame_g = 0;   inner_frame_b = 255; }
        else if (inner_frame_color == 3) { inner_frame_r = 0;   inner_frame_g = 255; inner_frame_b = 0; }
        else if (inner_frame_color == 4) { inner_frame_r = 255; inner_frame_g = 255; inner_frame_b = 255; }
        else if (inner_frame_color == 5) { inner_frame_r = 0;   inner_frame_g = 0;   inner_frame_b = 0; }
        else if (inner_frame_color == 6) { inner_frame_r = 255; inner_frame_g = 215; inner_frame_b = 0; }
        else if (inner_frame_color == 7) { inner_frame_r = 192; inner_frame_g = 192; inner_frame_b = 192; }


        for (int x = 0;x < image.width;++x) {
            for (int y = 0;y < image.height;++y) {


                if (x < frame2_size || x >= image.width - frame2_size ||
                    y < frame2_size || y >= image.height - frame2_size) {

                    image(x, y, 0) = frame_R;
                    image(x, y, 1) = frame_G;
                    image(x, y, 2) = frame_B;
                }

                if ((x >= start_line && x < end_line && y >= start_line && y < image.height - start_line) ||
                    (x >= image.width - end_line && x < image.width - start_line && y >= start_line && y < image.height - start_line) ||
                    (y >= start_line && y < end_line && x >= start_line && x < image.width - start_line) ||
                    (y >= image.height - end_line && y < image.height - start_line && x >= start_line && x < image.width - start_line)) {


                    image(x, y, 0) = inner_frame_r;
                    image(x, y, 1) = inner_frame_g;
                    image(x, y, 2) = inner_frame_b;
                }
            }
        }
    }
    return image;
}



//filter 12 (Blur_image) :
Image Blur_image(Image image) {

	Image blured_image = image;

		for (int i = 2; i < image.width - 2; ++i) {
			for (int j = 2; j < image.height - 2; ++j) {
				for (int c = 0; c < 3; ++c)
				{
					int sum = 0;

					for (int x = -2; x <= 2; ++x) {
						for (int y = -2; y <= 2; ++y) {
							sum += image(i + x, j + y, c);
						}
					}

						blured_image(i, j, c) = sum / 25;
				}
			}
		}

	return blured_image;
}



//filter 16 (Infrared_filter) :
Image Infrared_filter(Image image) {
	Image infrared_image(image.width, image.height);

	for (int i = 0; i < image.width; ++i){
		for (int j = 0; j < image.height; ++j){

			int R = image(i, j, 0);
			int G = image(i, j, 1);
			int B = image(i, j, 2);


			int avg = (R + G + B) / 3;

			infrared_image(i, j, 0) = 255;
			infrared_image(i, j, 1) = 255 - avg;
			infrared_image(i, j, 2) = 255 - avg;

		}
	}

	return infrared_image;
}