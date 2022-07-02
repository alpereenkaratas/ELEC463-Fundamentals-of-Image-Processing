/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip 
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;

int main(int argc, char **argv)
{
  
  // LAB 1

  // Adim 1 - Soru 1

  Image inputImage, outputImage;

  // giris goruntusu okundu
  char inputFileName[] = "3.4a.pgm";
  inputImage.readImage(inputFileName);

  // cikis goruntusu icin yazilan fonksiyondan dondurulen obje olusturulan yeni objeye atandi
  outputImage = inputImage.negativeImage();
  
  // cikis goruntusu yazdirildi
  char outputFileName[] = "3.4b_out.pgm";
  outputImage.writeImage(outputFileName);

  // Adim 1 - Soru 2

  Image inputImage2, outputImage2;

  char inputFileName2[] = "3.5a.pgm";
  inputImage2.readImage(inputFileName2);

  outputImage2 = inputImage2.logTransform();
  
  char outputFileName2[] = "3.5b_out.pgm";
  outputImage2.writeImage(outputFileName2);

  // Adim 1 - Soru 3

  Image inputImage3, outputImage3, outputImage4, outputImage5;

  char inputFileName3[] = "3.8a.pgm";
  inputImage3.readImage(inputFileName3);

  outputImage3 = inputImage3.gammaTransform(0.6);
  
  char outputFileName3[] = "3.8b_out.pgm";
  outputImage3.writeImage(outputFileName3,true);

  outputImage4 = inputImage3.gammaTransform(0.4);

  char outputFileName4[] = "3.8c_out.pgm";
  outputImage4.writeImage(outputFileName4,true);

  outputImage5 = inputImage3.gammaTransform(0.3);

  char outputFileName5[] = "3.8d_out.pgm";
  outputImage5.writeImage(outputFileName5,true);

  // Adim 1 - Soru 4

  Image inputImage4, outputImage6, outputImage7, outputImage8;

  char inputFileName4[] = "3.9a.pgm";
  inputImage4.readImage(inputFileName4);

  outputImage6 = inputImage4.gammaTransform(3.0);
  
  char outputFileName6[] = "3.9b_out.pgm";
  outputImage6.writeImage(outputFileName6,true);

  outputImage7 = inputImage4.gammaTransform(4.0);

  char outputFileName7[] = "3.9c_out.pgm";
  outputImage7.writeImage(outputFileName7,true);

  outputImage8 = inputImage4.gammaTransform(5.0);

  char outputFileName8[] = "3.9d_out.pgm";
  outputImage8.writeImage(outputFileName8,true);

  // Adim 1 - Soru 5

  Image inputImage5, outputImage9, outputImage10, outputImage11, outputImage12, outputImage13;

  char inputFileName5[] = "3.33a.pgm";
  inputImage5.readImage(inputFileName5);

  outputImage9 = inputImage5.meanFilter(3,3);
  
  char outputFileName9[] = "3.33b_out.pgm";
  outputImage9.writeImage(outputFileName9,true);

  outputImage10 = inputImage5.meanFilter(5,5);
  
  char outputFileName10[] = "3.33c_out.pgm";
  outputImage10.writeImage(outputFileName10,true);

  outputImage11 = inputImage5.meanFilter(9,9);
  
  char outputFileName11[] = "3.33d_out.pgm";
  outputImage11.writeImage(outputFileName11,true);

  outputImage12 = inputImage5.meanFilter(15,15);
  
  char outputFileName12[] = "3.33e_out.pgm";
  outputImage11.writeImage(outputFileName12,true);

  outputImage13 = inputImage5.meanFilter(35,35);
  
  char outputFileName13[] = "3.33f_out.pgm";
  outputImage13.writeImage(outputFileName13,true);

  // Adim 1 - Soru 6

  Image inputImage6, outputImage14, outputImage15;  

  char inputFileName6[] = "3.35a.pgm";
  inputImage6.readImage(inputFileName6);
  
  outputImage14 = inputImage6.meanFilter(3,3);

  char outputFileName14[] = "3.35b_out.pgm";
  outputImage14.writeImage(outputFileName14,true);

  outputImage15 = inputImage6.medianFilter(3,3);
  
  char outputFileName15[] = "3.35c_out.pgm";
  outputImage15.writeImage(outputFileName15,true);
  
  

  // Adim 2 - Foto 1

  
  Image inputImage7, outputImage16;

  char inputFileName7[] = "adim2_foto1.pgm";
  inputImage7.readImage(inputFileName7);

  outputImage16 = inputImage7.gammaTransform(3.0);

  char outputFileName16[] = "adim2_foto1_out.pgm";
  outputImage16.writeImage(outputFileName16,true);

  // Adim 2 - Foto 2

  Image inputImage8, outputImage17;

  char inputFileName8[] = "adim2_foto2.pgm";
  inputImage8.readImage(inputFileName8);

  outputImage17 = inputImage8.logTransform();

  char outputFileName17[] = "adim2_foto2_out.pgm";
  outputImage17.writeImage(outputFileName17,true);

  // Adim 2 - Foto 3

  Image inputImage9, outputImage18;

  char inputFileName9[] = "adim2_foto3.pgm";
  inputImage9.readImage(inputFileName9);

  outputImage18 = inputImage9.medianFilter(3,3);
  
  char outputFileName18[] = "adim2_foto3_out.pgm";
  outputImage18.writeImage(outputFileName18,true);

  
}
