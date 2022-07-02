/**************************************
 The original copy of the code can be found at http://web.eecs.utk.edu/~mkarakay/courses_files/testfiles.zip 
 and it is modified for ELM463/667
 **************************************/

#include "Image.h"

using namespace std;

int main(int argc, char **argv)
{

   // LAB 4

  // Soru 1

  Image inputImage343a, outputImage343b, outputImage343c, outputImage343_unsmask, outputImage343sobelXaxis, outputImage343sobelYaxis, 
  outputImage343d, outputImage343e, outputImage343f, outputImage343g, outputImage343h, input;

  // giris goruntusu okundu
  char inputFileName343a[] = "Fig0343(a).pgm";
  inputImage343a.readImage(inputFileName343a);

  // cikis goruntusu icin yazilan fonksiyondan dondurulen obje olusturulan yeni objeye atandi
  char outputFileName343b[] = "Fig0343(b)_out.pgm";
  outputImage343b = inputImage343a.laplacianFilter(3,3);

  // giris goruntusu yazdirildi
  outputImage343b.writeImage(outputFileName343b,true);

  outputImage343_unsmask = inputImage343a - outputImage343b;  // sharpened image bulmak icin oncelikle unsharped mask bulundu
  
  char outputFileName343c[] = "Fig0343(c)_out.pgm";
  outputImage343c = inputImage343a + outputImage343_unsmask;   // sharpened image (giris goruntusu + unsharped mask)
  outputImage343c.writeImage(outputFileName343c,true);

  char outputFileName343d[] = "Fig0343(d)_out.pgm";
  outputImage343sobelXaxis = inputImage343a.sobelFilterXaxis(3,3);  // x ekseni icin sobel filtresi uygulaniyor
  outputImage343sobelYaxis = inputImage343a.sobelFilterYaxis(3,3);  // y ekseni icin sobel filtresi uygulaniyor
  outputImage343d = outputImage343sobelXaxis + outputImage343sobelYaxis; // sobel goruntusu elde ediliyor
  outputImage343d.writeImage(outputFileName343d);

  char outputFileName343e[] = "Fig0343(e)_out.pgm";
  outputImage343e = outputImage343d.meanFilter(5,5); 
  outputImage343e.writeImage(outputFileName343e);

  char outputFileName343f[] = "Fig0343(f)_out.pgm";
  outputImage343f = outputImage343c * outputImage343e; 
  outputImage343f.writeImage(outputFileName343f,true);

  outputImage343f.readImage(outputFileName343f);   // goruntu tekrar okunmadiginda f ve g ayni cikiyordu. sorun boyle cozuldu

  char outputFileName343g[] = "Fig0343(g)_out.pgm";
  outputImage343g = inputImage343a + outputImage343f; 
  outputImage343g.writeImage(outputFileName343g,true);

  char outputFileName343h[] = "Fig0343(h)_out.pgm";
  outputImage343h = outputImage343g.gammaTransform(0.25); 
  outputImage343h.writeImage(outputFileName343h,true);

}
