/*


    filters 1 & 5 & 9 & 13 & Menu :
    احمد محمد عبد المحسن ميزار  (s33,s34) 20250058

    filters 2 & 6 & 10 & 14 :
    مارتن ايهاب سمير دوس        (s33,s34) 20250512

    filters 3 & 7 & 11 & 15 :
    محمد اسامة احمد عبدالله     (s33,s34) 20250540

    filters 4 & 8 & 12 & 16 :
    محمود مصطفى اسماعيل         (s33,s34) 20250616


    Project Links


    Video Link : https://drive.google.com/drive/folders/1dzN4Udi6aB2SAsHr6PzAEjAeIIhKGcSt
    Repo link : https://github.com/EngTuna/OOP.git
    Document Link :https://docs.google.com/document/d/1BQ2ynihaPigFOqslYTP9AvmkkwDmwgrM0secxzX4loQ/edit?usp=sharing

*/

#include<iostream>
#include "Image_Class.h"
using namespace std;




Image load(){
    cout<<"enter the image name with extension and if it is in another folder write the path"<<endl;
    string img_name;
    cin>>img_name;
    Image img(img_name);
    return img;
}

//filter 1:
Image gray_scale(Image& img){
    Image work(img.width,img.height);
    for(int y=0;y<img.height;y++){
        for(int x=0;x<img.width;x++){
           int rgb[3];
           for(int i=0;i<3;i++){
             rgb[i]= img.getPixel(x,y,i);
           }
           float scale=0.299*rgb[0]+0.587*rgb[1]+0.114*rgb[2];
           for (int j=0;j<3;j++){
                work.setPixel(x,y,j,scale);
           }
        }
    }
    return work;
}

//filter 2:
Image applyBlackAndWhite(Image img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            int val = (avg > 127) ? 255 : 0;
            img(i, j, 0) = img(i, j, 1) = img(i, j, 2) = val;
        }
    }
    return img;
}

//filter 3:
Image invertImage(Image img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < img.channels; ++k) {
                img(i, j, k) = 255 - img(i, j, k);
            }
        }
    }
    return img;
}

//filter 4:
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

//filter 5:
Image flipping(Image& img){
    cout<<"enter h for horizontal and v for vertical"<<endl;
    char c;
    cin>>c;
    Image work(img.width,img.height);
    if(c=='h'){
        for(int y=0;y<work.height;y++){
            int opposite=work.width-1;
            for(int x=0;x<work.width/2;x++){
                int r1=img.getPixel(x,y,0);
                int g1=img.getPixel(x,y,1);
                int b1=img.getPixel(x,y,2);

                int r2=img.getPixel(opposite,y,0);
                int g2=img.getPixel(opposite,y,1);
                int b2=img.getPixel(opposite,y,2);

                work.setPixel(opposite,y,0,r1);
                work.setPixel(opposite,y,1,g1);
                work.setPixel(opposite,y,2,b1);

                work.setPixel(x,y,0,r2);
                work.setPixel(x,y,1,g2);
                work.setPixel(x,y,2,b2);

                opposite--;

            }

        }
        if(img.width%2 !=0){
            for(int i=0;i<img.height;i++){
                int r=img.getPixel((img.width/2),i,0);
                int g=img.getPixel((img.width/2),i,1);
                int b=img.getPixel((img.width/2),i,2);

                work.setPixel((img.width/2),i,0,r);
                work.setPixel((img.width/2),i,1,g);
                work.setPixel((img.width/2),i,2,b);
            }
        }
    }


    else if(c=='v'){
        for(int x=0;x<work.width;x++){
            int opposite=work.height-1;
            for(int y=0;y<work.height/2;y++){
                int r1=img.getPixel(x,y,0);
                int g1=img.getPixel(x,y,1);
                int b1=img.getPixel(x,y,2);

                int r2=img.getPixel(x,opposite,0);
                int g2=img.getPixel(x,opposite,1);
                int b2=img.getPixel(x,opposite,2);

                work.setPixel(x,opposite,0,r1);
                work.setPixel(x,opposite,1,g1);
                work.setPixel(x,opposite,2,b1);

                work.setPixel(x,y,0,r2);
                work.setPixel(x,y,1,g2);
                work.setPixel(x,y,2,b2);

                opposite--;
            }
        }
        if(img.height%2 !=0){
            for(int i=0;i<img.width;i++){
                int r=img.getPixel(i,(img.height/2),0);
                int g=img.getPixel(i,(img.height/2),1);
                int b=img.getPixel(i,(img.height/2),2);

                work.setPixel(i,(img.height/2),0,r);
                work.setPixel(i,(img.height/2),1,g);
                work.setPixel(i,(img.height/2),2,b);
            }
        }

    }
    else{
        cout<<"invalid";
        return flipping(img);
    }


    return work;

}
//filter 6:
Image applyRotate(Image img) {
     cout<<"if you want to rotate it 90 degrees press 1"<<endl;
     cout<<"if you want to rotate it 180 degrees press 2"<<endl;
     cout<<"if you want to rotate it 270 degrees press 3"<<endl;



     int choice;
     cin>>choice;
     while(choice>3 || choice<1){
        cout<<"invalid number try again"<<endl;
        cin>>choice;
     }
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
    } else if(choice==3) {
        Image rotated(img.height, img.width);
        for (int i = 0; i < img.width; ++i)
            for (int j = 0; j < img.height; ++j)
                for (int c = 0; c < 3; ++c)
                    rotated(j, img.width - 1 - i, c) = img(i, j, c);
        return rotated;
    }
}


//filter 7:
Image processImageLight(Image img) {
    int choice;
    cout<<"enter 1 to brighten the image and 2 to darken it"<<endl;
    cin>>choice;
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
    return img;
}
//filter 8:
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


//filter 9 and its resize:
Image filter9_resize(Image image,int new_w,int new_h) {


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

Image Merge_image(Image img){
    cout<<"this filter needs a second image \n";
    Image img2=load();


    int H,W;
    if(img.height==img2.height){
        H=0;
    }
    else if(img.height>img2.height){
        H=1;
    }
    else{
        H=2;
    }
    if(img.width==img2.width){
        W=0;
    }
    else if(img.width>img2.width){
        W=1;
    }
    else{
        W=2;
    }


    if(H==0 &&W==0){
        Image work=img;
        for(int y=0;y<img.height;y++){
            for(int x=0;x<img.width;x++){
                for(int i=0;i<3;i++){
                    work(x,y,i)=(img(x,y,i)+img2(x,y,i))/2;
                }
            }
        }
        return work;
    }
    else{
        cout<<"the images are not the same size what do you want to do?"<<endl<<"if you want to crop the common area and merge it press 1"<<endl<<"if you want to resize the images to match each other press 2"<<endl;
        int choose;
        cin>>choose ;
        while(choose>2 || choose<1){
            cout<<"invalid option try again"<<endl;
            cout<<"the images are not the same size what do you want to do?"<<endl<<"if you want to crop the common area and merge it press 1"<<endl<<"if you want to resize the images to match each other press 2"<<endl;
            cin>>choose ;
        }


        int new_h=img.height;
        int new_w=img.width;


        if (choose==1){
            if(H==1){
                new_h=img2.height;
            }
            else if (H==2){
                new_h=img.height;
            }


            if(W==1){
                new_w=img2.width;
            }
            else if(W==2){
                new_w=img.width;
            }
            Image work(new_w,new_h);


            for(int y=0;y<new_h;y++){
                for(int x=0;x<new_w;x++){
                    for(int i=0;i<3;i++){
                        work(x,y,i)=(img(x,y,i)+img2(x,y,i))/2;
                    }
                }
            }
            return work;


        }
        else if(choose==2){

            if(H==1){
                new_h=img.height;
            }
            else if (H==2){
                new_h=img2.height;
            }


            if(W==1){
                new_w=img.width;
            }
            else if(W==2){
                new_w=img2.width;
            }
            Image work(new_w,new_h);

            img=filter9_resize(img,new_w,new_h);
            img2=filter9_resize(img2,new_w,new_h);


            for(int y=0;y<new_h;y++){
            for(int x=0;x<new_w;x++){
                for(int i=0;i<3;i++){
                    work(x,y,i)=(img(x,y,i)+img2(x,y,i))/2;
                }
            }

        }
        return work;



        }

    }






}


//filter 10:
Image applyEdgeDetection(Image img) {
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
    return img;
}


//filter 11:
Image cropImage(Image image) {
    int x, y, w, h;


    cout << "Enter starting point (x y): ";
    cin >> x >> y;


    cout << "Enter width and height to crop (w h): ";
    cin >> w >> h;


    if (x < 0 || y < 0 || x + w > image.width || y + h > image.height || w <= 0 || h <= 0) {
        cout << "Invalid crop dimensions! Out of image bounds.\n";
        return cropImage(image);
    }


    Image croppedImage(w, h);


    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                croppedImage(i, j, k) = image(x + i, y + j, k);
            }
        }
    }


    return croppedImage;

}

//filter 12:
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


//filter 13:
Image sunlight(Image img){
    for(int y=0;y<img.height;y++){
        for(int x=0;x<img.width;x++){
            int r= img(x,y,0)*1.15+15;
            int g= img(x,y,1)*1.05+15;
            int b=img(x,y,2)*.85;
            if(r>255){
                img(x,y,0)=255;
            }
            else{
                img(x,y,0)=r;
            }

            if(g>255){
                img(x,y,1)=255;
            }
            else{
                img(x,y,1)=g;
            }

            if(b>255){
                img(x,y,2)=255;
            }
            else{
                img(x,y,2)=b;
            }

        }


    }
    return img;
}


//filter 14:
Image applyTVEffect(Image img) {
    for (int j = 0; j < img.height; ++j) {
        if (j % 3 == 0) {
            for (int i = 0; i < img.width; ++i) {
                img(i, j, 0) *= 0.45;
                img(i, j, 1) *= 0.45;
                img(i, j, 2) *= 0.45;
            }
        }
    }
    return img;
}


//filter 15:
Image applyPurpleFilter(Image image) {
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
    return image;


}



//filter 16:
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




Image choice(Image img){

    cout<<"welcome in photo editor assignment"<<endl<<"for grayscale filter press 1"<<endl<<"for black and white filter press 2"<<endl<<"for inverting image filter press 3"<<endl<<"for image resize filter press 4"<<endl<<"for flipping filter press 5"<<endl<<"for rotating filter press 6"<<endl<<"for brightening and darkening filter press 7"<<endl<<"for adding frame press 8"<<endl;
    cout<<"for merge filter press 9"<<endl<<"for detect image edges filter press 10"<<endl<<"for crop images filter press 11"<<endl<<"for blur images press 12"<<endl<<"for sunlight filter press 13"<<endl<<"for tv effect filter press 14"<<endl<<"for purple filter press 15"<<endl<<"for infrared filter press 16"<<endl;

    int option;
    cin>>option;
    if(option==1){
        return gray_scale(img);
    }
    else if(option==2){
        return applyBlackAndWhite(img);
    }
    else if(option==3){
        return invertImage(img);
    }
    else if(option==4){
        return Resize_image(img);
    }
    else if(option==5){
        return flipping(img);
    }
    else if(option==6){
        return applyRotate(img);
    }
    else if(option==7){
        return processImageLight(img);
    }
    else if(option==8){
        return Adding_a_Frame_to_the_Picture(img);
    }
    else if(option==9){
        return Merge_image(img);
    }
    else if(option==10){
        return applyEdgeDetection(img);
    }
    else if(option==11){
        return cropImage(img);
    }
    else if(option==12){
        return Blur_image(img);
    }
    else if(option==13){
        return sunlight(img);
    }
    else if(option==14){
        return applyTVEffect(img);
    }
    else if(option==15){
        return applyPurpleFilter(img);
    }
    else if(option==16){
        return Infrared_filter(img);
    }
    else{
         cout<<"invalid option try again"<<endl;
         return choice(img);
    }
}







void save(Image img){
    cout<<"write the image name with extension"<<endl;
    string save_name;
    cin>>save_name;
    img.saveImage(save_name);
}

int sec_choice(Image& img,Image work){
    cout<<"if you want to save this filter and load a new image press 1"<<endl<<"if you want to save this filter and try another one on the original image press 2"<<endl<<"if you want to add another filter on top of the current one press 3"<<endl<<"if you want to save and quit press 4"<<endl;
    int x;
    cin>>x;

        if(x==1){
            save(work);
            img=load();
            return 1;
        }
        else if(x==2){
            save(work);
            return 2;
        }
        else if(x==3){
            img=work;
            return 3;
        }
        else if(x==4){
            save(work);
            return 4;
        }
        else{
            cout<<"invalid option try again"<<endl;
            return sec_choice(img,work);
        }

}
int main()
{
Image img=load();
Image wrk=img;
int counter=0;
while(counter!=4){
    wrk=choice(img);
    counter=sec_choice(img,wrk);
}


}



