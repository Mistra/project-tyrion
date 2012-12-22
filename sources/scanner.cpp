// to be compiled with -lpng

//attenzione: return e cout devono coincidere, errato per ora

#include <iostream>
#include <boost/gil/utilities.hpp>
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_dynamic_io.hpp>

void find_bobber (int min_width, int max_width, int min_height, int max_height) {
  boost::gil::rgb8_image_t im;
  boost::gil::png_read_image("/tmp/botscreen.png", im);

  for (int i=min_width; i<max_width; ++i) {
    for (int j=min_height; j<max_height; ++j) {
      boost::gil::rgb8_pixel_t pixel = view(im)(i, j);
      if ( (int)pixel[0] > 140 and (int)pixel[0] < 200 and
	   (int)pixel[1] > 135 and (int)pixel[1] < 200 and
	   (int)pixel[2] > 95 and (int)pixel[2] < 110) {
	std::cout << i <<" "<< j << std::endl;
	return;
      }
    }
  }
  std::cout << 0 <<" "<< 0 << std::endl;
}

int main()
{

  boost::gil::point2<std::ptrdiff_t> size = boost::gil::png_read_dimensions ("/tmp/botscreen.png");

  int width = (int)size.x;
  int height = (int)size.y;

  int max_height = height-height/100*25;
  int min_height = height/100*25;
  int max_width = width-width/100*25;
  int min_width = width/100*25;

  //std::cout<<"alt max: "<<max_height<< std::endl;

  find_bobber (min_width, max_width, min_height, max_height);

  

  return 0;
}
