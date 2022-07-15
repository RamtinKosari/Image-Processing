#include "Image.hpp"

Image::Image(int option) {
    switch(option) {
        //-- Gaussion Blur
        case 3:
            kernel[0][0] = 0.0625;
            kernel[0][1] = 0.125;
            kernel[0][2] = 0.0625;
            kernel[1][0] = 0.125;
            kernel[1][1] = 0.25;
            kernel[1][2] = 0.125;
            kernel[2][0] = 0.0625;
            kernel[2][1] = 0.125;
            kernel[2][2] = 0.0625;
        break;
        //-- Sharpen
        case 1:
            kernel[0][0] = 0;
            kernel[0][1] = -1;
            kernel[0][2] = 0;
            kernel[1][0] = -1;
            kernel[1][1] = 5;
            kernel[1][2] = -1;
            kernel[2][0] = 0;
            kernel[2][1] = -1;
            kernel[2][2] = 0;
        break;
        //-- Ridge Detection
        case 2:
            kernel[0][0] = -1;
            kernel[0][1] = -1;
            kernel[0][2] = -1;
            kernel[1][0] = -1;
            kernel[1][1] = 8;
            kernel[1][2] = -1;
            kernel[2][0] = -1;
            kernel[2][1] = -1;
            kernel[2][2] = -1;
        break;
    }
}

void Image::loadImage(string picturePath) {
    image = imread(picturePath, 0);
    imshow("Input", image);
    cout << "input size : " << image.rows << "x" << image.cols << endl;
}

void Image::applyFilter() {
    int counter1, counter2;
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            sumIndex = 0;
            for (int k = 0; k < 3; k++) {
                //-- Insert Kernel in Rows
                if (k == 0) {
                    counter1 = i;
                } else if (k == 1) {
                    counter1 = i + 1;
                } else if (k == 2) {
                    counter1 = i + 2;
                }
                for (int l = 0; l < 3; l++) {
                    //-- Insert Kernel in Columns
                    if (l == 0) {
                        counter2 = j;
                    } else if (l == 1) {
                        counter2 = j + 1;
                    } else if (l == 2) {
                        counter2 = j + 2;
                    }
                    sumIndex += kernel[k][l] * image.at<uchar>(counter1, counter2);
                }
            }
            image.at<uchar>(i, j) = sumIndex;
        }
    }
    cout << "output size : " << image.rows << "x" << image.cols << endl;
    imshow("Output", image);
    waitKey(0);
    destroyAllWindows();
}