
#ifndef __TP2_3BIM_2016__Image__
#define __TP2_3BIM_2016__Image__

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Image
{
  
public:
  
  Image( void );
  Image( std::string file );
  Image( const Image& image );
  Image(int L, int W, int** tab, int color);
  
  ~Image( void );
  
  void save( std::string file );
  
  
private:
  
  int            _w;      /*!< Image width (pixels)  */
  int            _h;      /*!< Image heigth (pixels) */
  int            _maxVal; /*!< Maximum canal value   */
  unsigned char* _data;   /*!< Image data            */
  
};

#endif /* defined(__TP2_3BIM_2016__Image__) */
