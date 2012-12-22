// to be compiled with -lpng

#include <iostream>
#include <sstream>
#include <boost/gil/extension/io/png_dynamic_io.hpp>

int main(int argc, char* argv[]) {
  try {
    
    if (argc != 3) {
      std::cout<<"no coordinates inserted";
      return 0;
    }
    std::stringstream string_x(argv[1]);
    std::stringstream string_y(argv[2]);
    int x, y;
    string_x >> x;
    string_y >> y;
    
    boost::gil::rgb8_image_t im;
    boost::gil::png_read_image("/tmp/botscreen.png", im);
    boost::gil::rgb8_pixel_t pixel = view(im)(x, y);
    
    if ( (int)pixel[0] < 140 )
      std::cout << "movement";
    else
      std::cout << "no movement";
  }
  catch (const std::ios_base::failure& e) {
    std::cout << "Couldn't open image";
  }
  return 0;
}

/*
  if ( ( (int)pixel[0] < 140 or (int)pixel[0] > 170 ) or
       ( (int)pixel[1] < 135 or (int)pixel[1] > 160 ) or
       ( (int)pixel[2] < 95 or (int)pixel[2] > 110) ) {
    std::cout << 1;
  }
*/

//#include <boost/gil/utilities.hpp>
//#include <boost/gil/gil_all.hpp>
