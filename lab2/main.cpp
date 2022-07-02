/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip 
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;

int main(int argc, char **argv)
{
  
  // LAB 2

  // Soru 1

  Image inputImage, outputImage;

  // giris goruntusu okundu
  char inputFileName[] = "Fig0316(1).pgm";
  inputImage.readImage(inputFileName);

  // cikis goruntusu icin yazilan fonksiyondan dondurulen obje olusturulan yeni objeye atandi
  outputImage = inputImage.histogramEqualization();
  
  // cikis goruntusu yazdirildi
  char outputFileName[] = "Fig0316(1)_out.pgm";
  outputImage.writeImage(outputFileName);

  Image inputImage2, outputImage2;

  char inputFileName2[] = "Fig0316(2).pgm";
  inputImage2.readImage(inputFileName2);

  outputImage2 = inputImage2.histogramEqualization();
  
  char outputFileName2[] = "Fig0316(2)_out.pgm";
  outputImage2.writeImage(outputFileName2);

  Image inputImage3, outputImage3;

  char inputFileName3[] = "Fig0316(3).pgm";
  inputImage3.readImage(inputFileName3);

  outputImage3 = inputImage3.histogramEqualization();
  
  char outputFileName3[] = "Fig0316(3)_out.pgm";
  outputImage3.writeImage(outputFileName3);

  Image inputImage4, outputImage4;

  char inputFileName4[] = "Fig0316(4).pgm";
  inputImage4.readImage(inputFileName4);

  outputImage4 = inputImage4.histogramEqualization();
  
  char outputFileName4[] = "Fig0316(4)_out.pgm";
  outputImage4.writeImage(outputFileName4);
  
  // Soru 2

  Image inputImage5, outputImage5, outputImage6, outputImage7;

  char inputFileName5[] = "soru2_foto.pgm";
  inputImage5.readImage(inputFileName5);

  outputImage5 = inputImage5.gammaTransform(1.1);
  
  char outputFileName5[] = "soru2_foto_aydinlik_out.pgm";
  outputImage5.writeImage(outputFileName5);

  outputImage6 = inputImage5.gammaTransform(0.7);
  
  char outputFileName6[] = "soru2_foto_karanlik_out.pgm";
  outputImage6.writeImage(outputFileName6);

  outputImage7 = inputImage5.logTransform();
  
  char outputFileName7[] = "soru2_foto_kontrast_out.pgm";
  outputImage7.writeImage(outputFileName7);

  Image inputImage6, inputImage7, inputImage8, outputImage8, outputImage9, outputImage10;

  char inputFileName6[] = "soru2_foto_aydinlik_out.pgm";
  inputImage6.readImage(inputFileName6);

  outputImage8 = inputImage6.histogramEqualization();

  char outputFileName8[] = "aydinlik_histogram_out.pgm";
  outputImage8.writeImage(outputFileName8);

  char inputFileName7[] = "soru2_foto_karanlik_out.pgm";
  inputImage7.readImage(inputFileName7);

  outputImage9 = inputImage7.histogramEqualization();
  
  char outputFileName9[] = "karanlik_histogram_out.pgm";
  outputImage9.writeImage(outputFileName9);

  char inputFileName8[] = "soru2_foto_kontrast_out.pgm";
  inputImage8.readImage(inputFileName8);

  outputImage10 = inputImage8.histogramEqualization();
  
  char outputFileName10[] = "kontrast_histogram_out.pgm";
  outputImage10.writeImage(outputFileName10); 

  // Soru 3

  // 3.40 icin (3.38 asagida)

  Image inputImage9, outputImage11, outputImage12, outputImage13, outputImage14;

  char inputFileName9[] = "Fig0340(a).pgm";
  inputImage9.readImage(inputFileName9);

  outputImage11 = inputImage9.gaussianFilter(5,5);

  char outputFileName11[] = "Fig0340(b)_out.pgm";
  outputImage11.writeImage(outputFileName11);

  outputImage12 = inputImage9 - outputImage11;

  char outputFileName12[] = "Fig0340(c)_out.pgm";
  outputImage12.writeImage(outputFileName12);
  
  outputImage13 = inputImage9 + outputImage12;

  char outputFileName13[] = "Fig0340(d)_out.pgm";
  outputImage13.writeImage(outputFileName13);

  outputImage14 = inputImage9 + outputImage12 + outputImage12 + outputImage12 + outputImage12;

  char outputFileName14[] = "Fig0340(e)_out.pgm";
  outputImage14.writeImage(outputFileName14);
    
  // 3.38 icin

  Image inputImage10, outputImage15, outputImage16, outputImage17, outputImage18, outputImage19;

  // 3.38a
  char inputFileName10[] = "Fig0338(a).pgm";
  inputImage10.readImage(inputFileName10);

  outputImage15 = inputImage10.laplacianFilter(3,3);

  char outputFileName15[] = "Fig0338(b)_out.pgm";
  outputImage15.writeImage(outputFileName15);

  // 3.38c
  outputImage16 = inputImage10.laplacianFilter(3,3);

  char outputFileName16[] = "Fig0338(c)_out.pgm";
  outputImage16.writeImage(outputFileName16);

  // 3.38d
  outputImage17 = inputImage10 - outputImage15;

  char outputFileName17[] = "Fig0338(d)_out.pgm";
  outputImage17.writeImage(outputFileName17);

  // 3.38e
  outputImage18 = inputImage10.sharpenedLaplacianFilter(3,3);
  outputImage19 = inputImage10 - outputImage18;

  char outputFileName19[] = "Fig0338(e)_out.pgm";
  outputImage19.writeImage(outputFileName19);


}
