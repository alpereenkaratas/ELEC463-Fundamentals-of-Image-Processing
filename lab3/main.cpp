/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip 
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;

int main(int argc, char **argv)
{
  
  // LAB 3

  // Soru 0

  Image q0Image, outputImageforInputImage, inputImage0, outputImage0;

  char imageq0[] = "imageForQ0.pgm";
  outputImageforInputImage = outputImageforInputImage.createImageforlab3q0();
  outputImageforInputImage.writeImage(imageq0);

  // giris goruntusu okundu
  char inputFileName0[] = "imageForQ0.pgm";
  inputImage0.readImage(inputFileName0);

  // cikis goruntusu icin yazilan fonksiyondan dondurulen obje olusturulan yeni objeye atandi
  char outputFileName0[] = "imageForQ0_out.pgm";
  outputImage0 = inputImage0.twoDimFourierTransform();

  outputImage0.writeImage(outputFileName0,true);

  // Soru 1

  Image inputImage425a, outputImage425b;

  // giris goruntusu okundu
  char inputFileName[] = "Fig0425(a).pgm";
  inputImage425a.readImage(inputFileName);

  // cikis goruntusu icin yazilan fonksiyondan dondurulen obje olusturulan yeni objeye atandi
  outputImage425b = inputImage425a.twoDimFourierTransform();
  
  // cikis goruntusu yazdirildi
  char outputFileName[] = "Fig0425(b)_out.pgm";
  outputImage425b = inputImage425a.moveImageToCenter();  // goruntuyu merkeze tasir
  outputImage425b = outputImage425b.twoDimFourierTransform();  // iki boyutlu fourier alinir
  outputImage425b = outputImage425b.logTransform();  // net gorebilmek icin log transformu alinir
  outputImage425b = outputImage425b.gammaTransform(0.8);  // goruntunun parlakligini duzeltmek icin gamma alinir
  outputImage425b = outputImage425b.negativeImage();  // goruntu beklenenin tam tersi oldugu icin negatifi alinir
  outputImage425b.writeImage(outputFileName,true);
  
  Image inputImage425c, outputImage425d;

  char inputFileName2[] = "Fig0425(c).pgm";
  inputImage425c.readImage(inputFileName2);

  char outputFileName2[] = "Fig0425(d)_out.pgm";
  outputImage425d = inputImage425c.moveImageToCenter();  // goruntuyu merkeze tasir
  outputImage425d = outputImage425d.twoDimFourierTransform();  // iki boyutlu fourier alinir
  outputImage425d = outputImage425d.logTransform();  // net gorebilmek icin log transformu alinir
  outputImage425d = outputImage425d.gammaTransform(0.8);  // goruntunun parlakligini duzeltmek icin gamma alinir
  outputImage425d = outputImage425d.negativeImage();  // goruntu beklenenin tam tersi oldugu icin negatifi alinir
  outputImage425d.writeImage(outputFileName2,true);

  Image inputImage429a, outputImage429b;

  char inputFileName3[] = "Fig0429(a).pgm";
  inputImage429a.readImage(inputFileName3);

  char outputFileName3[] = "Fig0429(b)_out.pgm";
  outputImage429b = inputImage429a.moveImageToCenter();  // goruntuyu merkeze tasir
  outputImage429b = outputImage429b.twoDimFourierTransform();  // iki boyutlu fourier alinir
  outputImage429b = outputImage429b.logTransform();  // net gorebilmek icin log transformu alinir
  outputImage429b = outputImage429b.gammaTransform(0.8);  // goruntunun parlakligini duzeltmek icin gamma alinir
  outputImage429b = outputImage429b.negativeImage();  // goruntu beklenenin tam tersi oldugu icin negatifi alinir
  outputImage429b.writeImage(outputFileName3,true);




}
