/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip 
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;

int main(int argc, char **argv)
{

  /* LAB 00 PGM okuma-yazma */

  /* 1.soru */

  
  Image inputImage;
  int row=15;
  int col=10;
  inputImage.createImage(row,col);

  //Image outputImage;
  int pix = 50;
  inputImage.setPixels(pix);

  char outputFileName[] = "out.pgm";
  inputImage.writeImage(outputFileName);
  

  /* 2.soru */

  Image inputImage2, outputImage;

  // giris goruntusu okundu
  char inputFileName[] = "Test_image.pgm";
  inputImage2.readImage(inputFileName);

  // cikis goruntusu icin yazilan fonksiyondan dondurulen obje olusturulan yeni objeye atandi
  outputImage = inputImage2.doubleSize();
  
  // cikis gorntusu yazdirildi
  char outputFileName2[] = "doubled.pgm";
  outputImage.writeImage(outputFileName2);

  outputImage = inputImage2.halfSize();
  
  char outputFileName3[] = "halved.pgm";
  outputImage.writeImage(outputFileName3);
  
}
