#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Configs.hpp"

class Image {
    private:
        Mat image;
        double kernel[3][3];
        double sumIndex;
    public:
        //-- Creates Kernel According to Selected Method
        //- image(Convolve Options)
        Image(int);
        //-- Loads Image From Given Path
        //- loadImage(path)
        void loadImage(string);
        //-- Apply Filter to Image
        void applyFilter();
};

#endif // IMAGE_HPP