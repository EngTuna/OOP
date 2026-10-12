#include<iostream>
#include "Image_Class.h"
using namespace std;
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
