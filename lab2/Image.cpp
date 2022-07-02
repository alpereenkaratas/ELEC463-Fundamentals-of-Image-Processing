/**********************************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip 
 and it is modified for ELM463/667
 
 * Image.cpp - the image library which implements
 *             the member functions defined in Image.h
 *
 * Author: Hairong Qi, ECE, University of Tennessee
 *
 * Created: 02/05/02
 *
 * Copyright (C) hqi@utk.edu
 **********************************************************/

#include "Image.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/**
 * Default constructor.
 */ 
Image::Image() {
  image = NULL;
  nrows = 0;
  ncols = 0;
  maximum = 255;
  //createImage(0, 0);
}

/**
 * Constructor for grayscale images.
 * @param nrows Numbers of rows (height).
 * @param ncols Number of columns (width).
 * @return The created image.
 */
Image::Image(int nRows, int nCols) {
  if (nRows<=0 || nCols<=0) {
    cout << "Image: Index out of range.\n";
    exit(3);
  }
  image = NULL;
  createImage(nRows, nCols);
}

/**
 * Copy constructor. 
 * @param img Copy image.
 * @return The created image.
 */
Image::Image(const Image &img) {
  int rows, cols;

  image = NULL;
  nrows = img.getRow();
  ncols = img.getCol();
  createImage(nrows, ncols);             // allocate memory
  
  for (rows=0; rows < nrows; rows++)
    for (cols=0; cols < ncols; cols++)
		image[rows * ncols + cols] = img(rows, cols);
}

/**
 * Destructor.  Frees memory.
 */
Image::~Image() {
  if (image)
    delete [] image;       // free the image buffer
}






/**
 * Allocate memory for the image and initialize the content to be 0.
 */
void Image::createImage() {

  if (image != NULL)
    delete [] image;

  maximum = 255;

  image = (float *) new float [nrows * ncols];
  if (!image) {
    cout << "CREATEIMAGE: Out of memory.\n";
    exit(1);
  }

  initImage();
}


/**
 * Allocate memory for the image and initialize the content to be zero.
 * @param r Numbers of rows (height).
 * @param c Number of columns (width).
 */
void Image::createImage(int numberOfRows, int numberOfColumns) {
  
  if (image != NULL)
    delete [] image;

  nrows = numberOfRows;
  ncols = numberOfColumns;
  maximum = 255;

  image = (float *) new float [nrows * ncols];
  if (!image) {
    cout << "CREATEIMAGE: Out of memory.\n";
    exit(1);
  }

  initImage();
}

/**
 * Initialize the image.
 * @para init The value the image is initialized to. Default is 0.0.
 */
void Image::initImage(float initialValue) {
  int i;

  for (i = 0; i < nrows * ncols; i++)
    image[i] = initialValue;
}

/**
 * Returns the total number of rows in the image.
 * @return Total number of rows.
 * \ingroup getset
 */
int Image::getRow() const {
  return nrows;
}

/**
 * Returns the total number of columns in the image.
 * @return Total number of columns.
 * \ingroup getset
 */
int Image::getCol() const {
  return ncols;
}

/**
 * Returns the maximum pixel value of a gray-level image. 
 * @return The intensity of that pixel.
 * \ingroup getset
 */
float Image::getMaximum() const {
  int i, j;
  float maxi=-10000;

 
  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
      if (maxi < image[i*ncols+j])
	maxi = image[i*ncols+j];
  
  return maxi;
}


/**
 * Returns the minimum pixel value of the image.
 * @return The minimum pixel value.
 * \ingroup getset
 */
float Image::getMinimum() const {
  int i, j;
  float mini=10000; 

  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
      if (mini > image[i*ncols+j])
	mini = image[i*ncols+j];

  return mini;
}



/**
 * Returns the pixel value at rows, cols
 * @return The pixel value
 * \ingroup getset
 */
float Image::getPix(int rows, int cols) {
  return image[rows * ncols + cols];
}


/**
 * Returns the image. 
 * @return a gray-scale image
 * \ingroup getset
 */
Image Image::getImage() const {
  Image temp;
  int rows, cols;
  
  temp.createImage(nrows, ncols);   // temp is a gray-scale image
  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
      temp(rows, cols) = image[rows * ncols + cols];
      
  return temp;
}

/**
 * Sets the total number of rows in an image.
 * @param r Total number of rows.
 * \ingroup getset
 */
void Image::setRow(int numberOfRows) {
  nrows = numberOfRows;
}

/**
 * Sets the total number of columns in an image.
 * @param c Total number of columns.
 * \ingroup getset
 */
void Image::setCol(int numberOfColumns) {
  ncols = numberOfColumns;
}


/**
 * Sets the pixel value at rows,cols.
 * @param row and col index.
 * \ingroup getset
 */
void Image::setPix(int rows, int cols, float value) {
  image[rows * ncols + cols] = value;
}


/**
 * Sets the image given a grayscale image. 
 * \ingroup getset
 */
void Image::setImage(Image &img) {
  int rows, cols;

  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
      image[rows * ncols + cols] = img(rows, cols);
}

/**
 * Overloading () operator
 * \ingroup overload
 * @param i Row
 * @param j Column
 */
float & Image::operator()(int rows, int cols) const {
  return image[rows * ncols + cols];
}

/**
 * Overloading = operator.
 * \ingroup overload
 * @param img Image to copy.
 * @return Newly copied image.
 */
const Image Image::operator=(const Image& img) {
  int rows, cols;

  if (this == &img)
    return *this;

  nrows = img.getRow();
  ncols = img.getCol();
  createImage(nrows, ncols);             

  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
	(*this)(rows, cols) = img(rows, cols);

  return *this;
}

/**
 * Overloading + operator.
 * \ingroup overload
 * @param img Image to add to specified image.
 * @return Addition of the two images.
 */
Image Image::operator+(const Image& img) const {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator+: "
         << "Images are not of the same size or type, can't do addition\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);
  
  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] + img(i,j);

  return temp;
}

/**
 * Overloading - operator.
 * \ingroup overload
 * @param img Image to subtract from specified image.
 * @return Subtraction of the two images.
 */
Image Image::operator-(const Image &img) const {
   int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator-: "
         << "Images are not of the same size or type, can't do subtraction\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);             
  
  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] - img(i,j);

  return temp;
}

/**
 * Overloading * operator.  This function does pixel by pixel multiplication.
 * \ingroup overload
 * @param img Image to multiply with specified image.
 * @return Multiplication of the two images.
 */
Image Image::operator*(const Image &img) const {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator*: "
         << "Images are not of the same size or type, can't do multiplication\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);             
  
  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] * img(i,j);

  return temp;
}

/**
 * Overloading / operator.  This function does pixel by pixel division.
 * Specified image is the dividend.
 * \ingroup overload
 * @param img Image to be divided (divisor).
 * @return Quotient of the two images.
 */
Image Image::operator/(const Image &img) const {
  int i, j, nr, nc;
  Image temp;

  nr = img.getRow();
  nc = img.getCol();

  if (nr != nrows || nc != ncols) {
    cout << "operator/: "
         << "Images are not of the same size or type, can't do division\n";
    exit(3);
  }
  temp.createImage(nrows, ncols);             
  
  for (i=0; i<nrows; i++)
    for (j=0; j<ncols; j++)
        temp(i,j) = image[i*ncols+j] / ( img(i,j) + 0.001 );

  return temp;
}


/**
 * Overloading << operator.  Output the image to the specified destination.
 * \ingroup overload
 * @param out The specified output stream (or output destination).
 * @param img Image to be output.
 * @result Output image to the specified file destination.
 */
ostream & operator<<(ostream &out, Image &img) {
  int rows, cols;
  

    for (rows = 0; rows < img.getRow(); rows++) {
      for (cols = 0; cols < img.getCol(); cols++)
        out << setw(4) << img(rows, cols) << ' ';
      out << endl;
    }

  return out; 
}

/**
 * Overloading / operator.  The left operand is the image and the right
 * is the dividend (a double point number). Each pixel in the image is 
 * divided by the double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param val A double point number as the right operand.
 * @result Image divided by a double point number.
 */
Image operator/(Image &img, double val) {
  int i, j, nr, nc;
  Image temp;
  
  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);
  
  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) / val;
  
  return temp;
}

/**
 * Overloading * operator.  The left operand is the image and the right
 * is a double point number. Each pixel in the image is multiplied by the
 * double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param s A double point number as the right operand.
 * @result Image multiplied by a double point scalar.
 */
Image operator*(Image &img, double s) {
  int i, j, nr, nc;
  Image temp;
  
  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);
  
  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) * s;
  
  return temp;
}


/**
 * Overloading + operator.  The left operand is the image and the right
 * is a double point number. Each pixel in the image is added by the
 * double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param s A double point number as the right operand.
 * @result Image add a double point scalar.
 */
Image operator+(Image &img, double s) {
  int i, j, nr, nc;
  Image temp;
  
  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);
  
  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) + s;
  
  return temp;
}  
  
/**
 * Overloading - operator.  The left operand is the image and the right
 * is a double point number. Each pixel in the image is subtracted by the
 * double point number.
 * \ingroup overload
 * @param img Image as the left operand.
 * @param s A double point number as the right operand.
 * @result Image subtract a double point scalar.
 */
Image operator-(Image &img, double s) {
  int i, j, nr, nc;
  Image temp;
  
  nr = img.getRow();
  nc = img.getCol();
  temp.createImage(nr, nc);
  
  for (i=0; i<nr; i++)
    for (j=0; j<nc; j++)
        temp(i,j) = img(i,j) - s;
  
  return temp;
} 

/**
 * Read image from a file                     
 * @param fname The name of the file 
 * @return An Image object
 */
  void Image::readImage(char *fname) {
  ifstream ifp;
  char dummy[80];
  unsigned char *img;
  int rows, cols;
  int nRows, nCols, nt, maxi;

  ifp.open(fname, ios::in | ios::binary);

  if (!ifp) {
    cout << "readImage: Can't read image: " << fname << endl;
    exit(1);
  }

  // identify image format
  ifp.getline(dummy, 80, '\n');

  if (dummy[0] == 'P' && dummy[1] == '5') 
     ;
  else {
    cout << "readImage: Can't identify image format." << endl;
    exit(1);
  }

  // skip the comments
  ifp.getline(dummy, 80, '\n');

  while (dummy[0] == '#') {
    ifp.getline(dummy, 80, '\n');
  }

  // read the row number and column number
  sscanf(dummy, "%d %d", &nCols, &nRows);

  // read the maximum pixel value
  ifp.getline(dummy, 80, '\n');
  sscanf(dummy, "%d", &maxi); 
  if (maxi > 255) {
    cout << "Don't know what to do: maximum value is over 255.\n";
    exit(1);
  }

  if (image != NULL)
  delete [] image;
  
  nrows = nRows;
  ncols = nCols;
  maximum = 255;
  
  // read the image data
  img = (unsigned char *) new unsigned char [nRows * nCols];
  if (!img) {
    cout << "READIMAGE: Out of memory.\n";
    exit(1);
  }
  image = (float *) new float [nRows * nCols];
  if (!image) {
    cout << "READIMAGE: Out of memory.\n";
    exit(1);
  }

    ifp.read((char *)img, (nRows * nCols * sizeof(unsigned char)));
    
    for (rows = 0; rows < nRows; rows++)
      for (cols = 0; cols < nCols; cols++)
          image[rows * nCols + cols] = (float) img[rows * nCols + cols];
      
  ifp.close();
  
  delete [] img;
}


/**
 * Write image buffer to a file.
 * @param fname The output file name.
 */
void Image::writeImage(char *fname, bool flag) {
  ofstream ofp;
  int i, j;
  int nRows, nCols, nt;
  unsigned char *img;

  ofp.open(fname, ios::out | ios::binary);

  if (!ofp) {
    cout << "writeImage: Can't write image: " << fname << endl;
    exit(1);
  }


  ofp << "P5" << endl;
  ofp << ncols << " " << nrows << endl;

 
  ofp << 255 << endl;
  
  

  // convert the image data type back to unsigned char
  img = (unsigned char *) new unsigned char [nrows * ncols];
  if (!img) {
    cout << "WRITEIMAGE: Out of memory.\n";
    exit(1);
  }

  float maxi = getMaximum();
  float mini = getMinimum();
  
  
    for (i = 0; i< nrows; i++)
      for (j = 0; j < ncols; j++) {
	  // rescale if the flag is set
	  if ((maxi != mini) && flag == true)
	    img[i * ncols + j] = (unsigned char)  ((image[i * ncols + j]-mini)/(float)(maxi-mini)*255.0); 
	  // any intensity that is larger than the maximum would be set as maximum
	  else if (image[i * ncols + j] > 255)
	    img[i * ncols + j] = 255;
	  else if (image[i * ncols + j] < 0)
	    img[i * ncols + j] = 0;
	  else
	    img[i * ncols + j] = (unsigned char)  image[i * ncols + j]; 
      }
      
    ofp.write((char *)img, (nrows * ncols * sizeof(unsigned char)));


  ofp.close();
  delete [] img;
}




// YOUR FUNCTIONS

/**
 * Returns the image. 
 * @return a gray-scale image
 * \ingroup getset
 */
Image Image::thresholdImage(float thresholdValue, float lowValue, float highValue) {
  Image temp;
  int rows, cols;
  
  temp.createImage(nrows, ncols);   // temp is a gray-scale image
  for (rows = 0; rows < nrows; rows++)
    for (cols = 0; cols < ncols; cols++)
      if (image[rows * ncols + cols] <= thresholdValue) 
	temp(rows, cols) = lowValue;
      else
	temp(rows, cols) = highValue;
      
      
  return temp;
}

/*************/

void Image::setPixels(float value) {

  int holdValue = value;
  int r, c;

  for(r = 0; r < nrows; r++){
    for(c = 0; c < ncols; c++){
       image[r * ncols + c] = value;
       value++;
    }
    holdValue++;
    value = holdValue;
  }

}

Image Image::doubleSize() {

  Image doubledImage;
  int rows, cols, nnrows, nncols;
  // 2 katina cikmasi gerektigi icin rows ve columns 2 ile carpildi 
  nnrows = nrows * 2;
  nncols = ncols * 2;
  
  doubledImage.createImage(nnrows, nncols);  
  for (rows = 0; rows < nnrows; rows++){
    for (cols = 0; cols < nncols; cols++){
      doubledImage(rows,cols) = image[(rows/2) * ncols + (cols/2)];  // her bir piksel degerini yeni goruntude uygun yere yerlestirmek icin rows-columns 2'ye bolundu
    }
  }

  return doubledImage;
  
}

Image Image::halfSize() {

  Image halvedImage;
  int rows, cols, nnrows, nncols;
  // Yariya bolunmesi gerektigi icin rows ve columns 2'ye bolundu
  nnrows = nrows / 2;
  nncols = ncols / 2;
  
  halvedImage.createImage(nnrows, nncols);  
  for (rows = 0; rows < nnrows; rows++){
    for (cols = 0; cols < nncols; cols++){
      halvedImage(rows,cols) = image[(rows*2) * ncols + (cols*2)]; // her bir piksel degerini yeni goruntude uygun yere yerlestirmek icin rows-columns 2 ile carpildi
    }
  }

  return halvedImage;

}


Image Image::negativeImage(){

  Image negImg;
  int rows, cols;
  
  negImg.createImage(nrows, ncols);  
  for (rows = 0; rows < nrows; rows++){
    for (cols = 0; cols < ncols; cols++){
      negImg(rows,cols) = 255-image[rows * ncols + cols];   // 8 bit goruntu icin max deger 255 oldugu icin, ilgili piksel degerleri 255'ten cikarildiginda istenilen negatiflik elde edilir
    }
  }

  return negImg;

}

Image Image::logTransform(){

  Image logImg;
  int c = 1;
  int rows, cols;
  float pixVal;
  float pixMax = 255.0; // 8 bit goruntu icin max piksel degeri
  
  logImg.createImage(nrows, ncols);  
  for (rows = 0; rows < nrows; rows++){
    for (cols = 0; cols < ncols; cols++){
      pixVal = image[rows * ncols + cols];    // goruntunun piksel degeri, pixVal isimli degiskene atandi
      logImg(rows,cols) = (float)(pixMax / pixVal) * (c * log(1 + pixVal)); // pixMax/pixVal islemi, 0-255 araligi log alma islemi sonucu daraldigi icin ornekleme yapmak amaciyla kullanilir
    }
  }

  return logImg;

}

Image Image::gammaTransform(float gamVal){

  Image gamImg;
  int c = 1;
  int rows, cols;
  float pixVal;
  float pixMax = 255.0; // 8 bit goruntu icin max piksel degeri
  float epsilon = 8.85 * pow(10,-12);
  
  gamImg.createImage(nrows, ncols);  
  for (rows = 0; rows < nrows; rows++){
    for (cols = 0; cols < ncols; cols++){
      pixVal = image[rows * ncols + cols];
      gamImg(rows,cols) = c * pow((pixVal + epsilon),gamVal);  // gamma transform formulu
    }
  }

  return gamImg;

}

Image Image::meanFilter(int size_m, int size_n){
  
  Image smoothedImg;
  int rows, cols;
  float pixVal;
  int a,b,i,j;
  float sum = 0.0;

  a = (size_m-1)/2;   // maskedeki for dongusu icin (formul)
  b = (size_n-1)/2;   // maskedeki for dongusu icin (formul)
  
  smoothedImg.createImage(nrows, ncols);  
  for (rows = 0; rows < nrows; rows++){
    for (cols = 0; cols < ncols; cols++){
      for(i = -a; i <= a; i++){           // toplam sembollu mean formulu icin (burada maske icine girilir)
        for(j = -b; j <= b; j++){         // toplam sembollu mean formulu icin
          if((rows+i) < 0 || (cols+j) < 0 || (rows+i) > nrows || (cols+j) > ncols){   // maskenin matris sinirlari disina cikmasi durumunun kontrolu
            smoothedImg(rows,cols) = 0; // ilgili piksellerin maskenin disinda olmasi durumunda direkt 0 degeri atanir
          }
          else{
            sum += image[(rows+i) * ncols + (cols+j)];  // averaj almanin on asamasi olarak ilgili piksel degerleri toplanir
          }        
        }
      }
      pixVal = sum / (size_m * size_n);    // averaj alinir (toplamin matris boyutlari carpimina bolumu)
      smoothedImg(rows,cols) = pixVal;
      sum = 0;   // her piksel degeri icin toplam degeri degisecegi icin, yeni piksel degerine gecildiginde bu deger sifirlanmalidir
    }
  }

  return smoothedImg;

}

int Image::findMedian(int A[], int arraySize){

  int temp;

  // medyan bulmadan once, dizinin asagidaki gibi kucukten buyuge dogru siralanmasi gerekir
  for(int i=0;i<arraySize-1;i++){
    for(int j=0;j<arraySize-1-i;j++){
      if(A[j]>A[j+1]){
        temp=A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
      }
    }
  }
  // dizi kucukten buyuge siralandi
  
  return A[(arraySize-1)/2]; // tek sayili bir boyuta sahip dizide asagidaki gibi (dizi boyutunun bir eksiginin yarisi) ortanca indexin elemanini, yani medyani geri dondurur

}

Image Image::medianFilter(int size_m, int size_n){
  
  Image medianFilteredImg;
  int rows, cols;
  float pixVal;
  int a,b,i,j;
  int median;

  a = (size_m-1)/2;  // maskedeki for dongusu icin (formul)
  b = (size_n-1)/2;  // maskedeki for dongusu icin (formul)

  int arr[size_m*size_n+1];   // maskenin (matrisin) elemanlarini doldurmak icin boyutu boyutlarin carpimindan olusan bir matris tanimlandi
  int k = 0;   // matris indexi icin
  
  medianFilteredImg.createImage(nrows, ncols);  
  for (rows = 0; rows < nrows; rows++){
    for (cols = 0; cols < ncols; cols++){
      for(i = -a; i <= a; i++){    // maskenin icine girilir
        for(j = -b; j <= b; j++){
          if((rows+i) < 0 || (cols+j) < 0 || (rows+i) > nrows || (cols+j) > ncols){  // maskenin matris sinirlari disina cikmasi durumunun kontrolu
            j++;  // ilgili piksellerin maskenin disinda olmasi durumunda diger piksele gecilir
          }
          else{
            arr[k] = image[(rows+i) * ncols + (cols+j)];    // maske matrisi, bir dizinin icine doldurulur (kucukten buyuge siralamak icin fonksiyona gonderilecek)
            k++;
          }    
        }
      }
      median = findMedian(arr, size_m*size_n);   // ilgili piksel icin ilgili maskeden elde edilen dizi yazilan medyan bulma fonksiyonuna gonderilir ve medyan degeri alinir
      pixVal = median;
      medianFilteredImg(rows,cols) = pixVal;    // piksel degeri doldurulur
      k = 0;   // bir sonraki piksel icin yeni arrayin doldurulmasi gerekir, bu yüzden array indexi sifirlanir
    }
  }

  return medianFilteredImg;

}

Image Image::histogramEqualization(){

  Image histImg;
  histImg.createImage(nrows, ncols); 

  int rows, cols;
  int pixMax = 255; // 8 bit goruntu icin max piksel degeri
  // histogramin h(r), P(r), T(r) ve s degerleri icin olusturulan arrayler
  float histogramArrH[pixMax+1];  // h(r)
  float histogramArrP[pixMax+1];  // P(r)
  float histogramArrT[pixMax+1];  // T(r)
  float histogramArrS[pixMax+1];  // s (kesirli hali)
  int sOut[pixMax+1]; // yuvarlanmis hali
  int ctr = 0;
  int j = 0;
  
  for (int i = 0; i < pixMax+1; i++){  // sonraki islemlerde (arrayin icinin doldurulmasinda) sorun olmamasi icin butun arraylerin icleri sifirlandi
    histogramArrH[i] = 0;
    histogramArrP[i] = 0;
    histogramArrT[i] = 0;
    histogramArrS[i] = 0;
    sOut[i] = 0;
  }
  
  // goruntu icindeki her bir pikselden kacar adet oldugunun bulunmasi icin yazilan kod blogu (h(r) bulunacak)
  for (rows = 0; rows < nrows; rows++){
    for (cols = 0; cols < ncols; cols++){
      for (int i = 0; i < pixMax+1; i++){     // 0-256  arasi saymak icin
        if(i == image[rows * ncols + cols]){
          ctr++;
          histogramArrH[i] += ctr;  // her bir piksel icin array dolduruluyor
        }
      }
      ctr = 0;  // farkli bir piksel degerini saymak icin sayac sifirlaniyor
    }
  }

  // bulunan piksel sayilirinin toplam piksel sayisina bolumu yapiliyor (P(r) bulunuyor)
  for (int i = 0; i < pixMax+1; i++){
    histogramArrP[i] = histogramArrH[i] / (nrows*ncols);
  }

  // T(r) bulunacak
  for(int i = 0; i < pixMax+1; i++){ 
    if(i == 0){
      histogramArrT[i] += histogramArrP[i];   // index sifir ise T(r)'nin ilk degeri P(r)'nin ilk degerine esit olur
    }
    else{
      histogramArrT[i] += histogramArrP[i] + histogramArrT[i-1];   // P(r) ile T(r)'nin bir onceki degerinin toplami yeni T(r) degerini bulmayi saglar
    }
  }    
  

  // s degeri bulunacak (float halinde)
  for (int i = 0; i < pixMax+1; i++){
    histogramArrS[i] = histogramArrT[i] * 255;  // 255 ile carpilmasinin sebebi ornekleme yapilmasi. Normalde sonuc 0-1 arasi deger alirken piksel degerleri 0-255 arasinda degisir. Bu yuzden T(r) degerleri 255 ile carpilarak orneklenir
  }

// elde edilen flaot halindeki s degerlerinin tam sayiya donusurken yuvarlanmasi gerekir. Asagidaki kod blogu ile bu saglanmis olur
for(int i = 0; i < pixMax+1; i++){
  if((1-histogramArrS[i] > 0)){   // 0'dan daha buyuk sonuc cikmasi durumunda deger 1'e yuvarlanir
    sOut[i] = 1;
  }
  else if(  (histogramArrS[i]-(int)histogramArrS[i]) > 0.5   ){   // .5'ten daha buyuk bir degerde sayi bir ust tamsayiya yuvarlanir
    sOut[i] = (int)histogramArrS[i] + 1;
  }
  else{
    sOut[i] = (int)histogramArrS[i];  // harici durumlarda deger direkt olarak kendisine esittir
  }
}

// elde edilen nihai s sonuclarina gore histogram equalization goruntusu elde edilir
for (rows = 0; rows < nrows; rows++){
  for (cols = 0; cols < ncols; cols++){
    for (int i = 0; i < pixMax+1; i++){ 
      if(i == image[rows * ncols + cols]){
          histImg(rows,cols) = sOut[i];
      }
    }
  }
}

  return histImg;

}

Image Image::gaussianFilter(int m, int n){

  Image gaussianImg;
  gaussianImg.createImage(nrows, ncols);

  float mask[m][n];
  int pixVal = 0;
  float sigma = 3.0;
  float expNominator;
  float denominator = 2.0 * sigma * sigma;

  float sum = 0.0;

  // G(x,y) = (1/(2*pi)/sigma^2) * exp(-(x^2+y^2)/(2*sigma^2)) gaussian filter formulunun kod blogu asagidaki gibidir
  for (int i = -m/2; i <= m/2; i++) {
      for (int j = -n/2; j <= n/2; j++) {
          expNominator = sqrt(i * i + j * j);
          mask[i + m/2][j + n/2] = (exp(-(expNominator * expNominator) / denominator)) / (M_PI * denominator);  // = G(x,y)
          sum += mask[i + m/2][j + n/2];   // sonrasinda normalize islemi yapilmasi adina piksel degerleri toplaniyor
      }
  }

  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      mask[i][j] /= sum;  // normalize islemi yapiliyor
    } 
  }

  // maskeleme yapiliyor 
  for (int rows = 0; rows < nrows; rows++){
    for (int cols = 0; cols < ncols; cols++){
      for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
          if((rows+i) < 0 || (cols+j) < 0 || (rows+i) > nrows || (cols+j) > ncols){  // maskenin matris sinirlari disina cikmasi durumunun kontrolu
            j++;  // ilgili piksellerin maskenin disinda olmasi durumunda diger piksele gecilir
          }
          else{
            pixVal += mask[i][j] * image[(rows+i) * ncols + (cols+j)];   // maskenin ilgili piksel degeri ile goruntunun ilgili piksel degeri caprilip toplam sonuca (pixVal) ekleniyor
          }  
        }
      }
      gaussianImg(rows,cols) = pixVal;
      pixVal = 0;   // goruntunun sonraki pikselleri icin pixVal degeri sifirlaniyor
    }
  } 

  return gaussianImg;
         
}

Image Image::laplacianFilter(int m, int n){

  Image laplacianImg;
  laplacianImg.createImage(nrows, ncols);

  int mask[3][3] = {0, -1, 0, -1, 4, -1, 0, -1, 0};   // 3x3'luk bir laplacian filtresi icin maskenin ici ilgili degerlerle dolduruldu
  int pixVal = 0;

// maskeleme yapiliyor
for (int rows = 0; rows < nrows; rows++){
  for (int cols = 0; cols < ncols; cols++){
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if((rows+i) < 0 || (cols+j) < 0 || (rows+i) > nrows || (cols+j) > ncols){  // maskenin matris sinirlari disina cikmasi durumunun kontrolu
          j++;  // ilgili piksellerin maskenin disinda olmasi durumunda diger piksele gecilir
        }
        else{
          pixVal += mask[i][j] * image[(rows+i) * ncols + (cols+j)];  // maskenin ilgili piksel degeri ile goruntunun ilgili piksel degeri caprilip toplam sonuca (pixVal) ekleniyor
        }  
      }
    }
    laplacianImg(rows,cols) = pixVal;
    pixVal = 0;   // goruntunun sonraki pikselleri icin pixVal degeri sifirlaniyor
  }
} 

return laplacianImg;

}

Image Image::sharpenedLaplacianFilter(int m, int n){

  Image sharpenedLaplacianImg;
  sharpenedLaplacianImg.createImage(nrows, ncols);

  int mask[3][3] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};   // 3x3'luk bir sharpened laplacian filtresi icin maskenin ici ilgili degerlerle dolduruldu
  int pixVal = 0;

for (int rows = 0; rows < nrows; rows++){
  for (int cols = 0; cols < ncols; cols++){
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if((rows+i) < 0 || (cols+j) < 0 || (rows+i) > nrows || (cols+j) > ncols){  // maskenin matris sinirlari disina cikmasi durumunun kontrolu
          j++;  // ilgili piksellerin maskenin disinda olmasi durumunda diger piksele gecilir
        }
        else{
          pixVal += mask[i][j] * image[(rows+i) * ncols + (cols+j)];    // maskenin ilgili piksel degeri ile goruntunun ilgili piksel degeri caprilip toplam sonuca (pixVal) ekleniyor
        }  
      }
    }
    sharpenedLaplacianImg(rows,cols) = pixVal;
    pixVal = 0;   // goruntunun sonraki pikselleri icin pixVal degeri sifirlaniyor
  }
} 

return sharpenedLaplacianImg;

}

  //END OF YOUR FUNCTIONS //
  
  
