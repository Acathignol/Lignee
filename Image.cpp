
#include "Image.h"


/**
 * \brief    Default constructor
 * \details  --
 * \param    void
 * \return   \e void
 */
Image::Image( void )
{
  _w      = 0;
  _h      = 0;
  _maxVal = 0;
  _data   = nullptr;
}

/**
 * \brief    Constructor
 * \details  --
 * \param    std::string file
 * \return   \e void
 */
Image::Image( std::string file )
{
  std::ifstream f(file.c_str(), std::ios::in);
  std::string p6;
  f >> p6;
  f >> _w >> _h >> _maxVal;
  f.get();
  _data = new unsigned char[_w*_h*3];
  f.read((char*)_data, sizeof(unsigned char)*_w*_h*3);
  f.close();
}

/**
 * \brief    Copy constructor
 * \details  --
 * \param    const Array& array
 * \return   \e void
 */
Image::Image( const Image& image )
{
  _w      = image._w;
  _h      = image._h;
  _maxVal = image._maxVal;
  _data   = new unsigned char[_w*_h*3];
  memcpy(_data, image._data, sizeof(unsigned char)*_w*_h*3);
}

/**
 * \brief    Constructor Creating the image in binary from 0 and 1
 * \details  color: 0=Black0 and Whatever1; 1=White0 and Black1
 * \param    size(L) and tab
 * \return   \e void  
 */

Image::Image(int L, int W, int** tab,int color)
{
    _w    = L;
  _h      = W;
  
  _maxVal = 255;
  _data   = new unsigned char[_w*_h*3];
  memcpy(_data, _data, sizeof(unsigned char)*_w*_h*3);
  int index=0;
  if (color==0){
    for (int x = 0; x < _w; x++)
    {
      for (int y = 0; y < _h; y++)
      {
        if (tab[x][y]==0) //Le mort est noir
        {
          _data[index]=(unsigned char)0;
          index++;
          _data[index]=(unsigned char)0;
          index++;
          _data[index]=(unsigned char)0;
          index++;
        }
        else if (tab[x][y]==1) //GB est bleu/vert
        {
          _data[index]=(unsigned char)10;
          index++;
          _data[index]=(unsigned char)150;
          index++;
          _data[index]=(unsigned char)130;
          index++;
        }
        else //GA est rouge
        {
          _data[index]=(unsigned char)150;
          index++;
          _data[index]=(unsigned char)20;
          index++;
          _data[index]=(unsigned char)50;
          index++;
        }
      }
    }
  }
  else if (color==1){//NOTHING TO UNDERSTAND, UNUSED FOR NOW.. Maybe later... Who knows?!
    for (int x = 0; x < _w; x++)
    {
      for (int y = 0; y < _h; y++)
      {
        _data[index]=(unsigned char)tab[x][y];
        index++;
        _data[index]=(unsigned char)tab[x][y];
        index++;
        _data[index]=(unsigned char)tab[x][y];
        index++;
      }
    }
  }
}

/**
 * \brief    Destructor
 * \details  --
 * \param    void
 * \return   \e void
 */
Image::~Image( void )
{
  delete[] _data;
  _data = nullptr;
}

/**
 * \brief    Save the image in a file
 * \details  --
 * \param    std::string file
 * \return   \e void
 */
void Image::save( std::string file )
{
  std::ofstream f(file.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
  f << "P6\n" << _w << " " << _h << "\n" << _maxVal << "\n";
  f.write((char*)_data, sizeof(char)*_w*_h*3);
  f.close();
}


