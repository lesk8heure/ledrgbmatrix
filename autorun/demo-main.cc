// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
//
// This code is public domain
// (but note, once linked against the led-matrix library, this is
// covered by the GPL v2)
//
// This is a grab-bag of various demos and not very readable.
#include "led-matrix.h"
#include "threaded-canvas-manipulator.h"
#include "pixel-mapper.h"
#include "graphics.h"

#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <algorithm>

using std::min;
using std::max;

#define TERM_ERR  "\033[1;31m"
#define TERM_NORM "\033[0m"

using namespace rgb_matrix;

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

class pixel_defil : public ThreadedCanvasManipulator {
public:
  pixel_defil(Canvas *m) : ThreadedCanvasManipulator(m) {}
    //const int width = canvas()->width() - 1;
    //const int height = canvas()->height() - 1;
	int coor_x = 10;
	int coor_y = 10;
	int rayon = 5;
	int i=1;
	int j=1;
	void Run() {

	for (j = 1; j < 50; j++) 
	{
	for (i = 1; i < 40; i++) 
		{
			coor_x++;
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(255, 255, 255));//ecrire
			usleep(10 * 1000);//laisser a l'écran pour 100ms
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(0, 0, 0));//effacer
		}
		
	for (i = 1; i < 16; i++) 
		{
			coor_y++;
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(255, 0, 255));//ecrire
			usleep(10 * 1000);//laisser a l'écran pour 100ms
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(0, 0, 0));//effacer
		}
		
	for (i = 1; i < 40; i++) 
		{
			coor_x--;
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(255, 255, 0));//ecrire
			usleep(10 * 1000);//laisser a l'écran pour 100ms
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(0, 0, 0));//effacer
		}
		
	for (i = 1; i < 16; i++) 
		{
			coor_y--;
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(0, 255, 255));//ecrire
			usleep(10 * 1000);//laisser a l'écran pour 100ms
			DrawCircle(canvas(), coor_x, coor_y, rayon, Color(0, 0, 0));//effacer
		}
	j=1;
	}
		
  }
};



int main(int argc, char *argv[]) {
  int runtime_seconds = -1;
  int demo = -1;
  int scroll_ms = 30;

  const char *demo_parameter = NULL;
  RGBMatrix::Options matrix_options;
  rgb_matrix::RuntimeOptions runtime_opt;

  // These are the defaults when no command-line flags are given.
  matrix_options.rows = 32;
  matrix_options.cols = 64;
  matrix_options.chain_length = 1;
  matrix_options.parallel = 1;

  // First things first: extract the command line flags that contain
  // relevant matrix options.
  //if (!ParseOptionsFromFlags(&argc, &argv, &matrix_options, &runtime_opt)) {
    //return usage(argv[0]);
  //}

  int opt;
  RGBMatrix *matrix = CreateMatrixFromOptions(matrix_options, runtime_opt);
  if (matrix == NULL)
    return 1;

  Canvas *canvas = matrix;

  // The ThreadedCanvasManipulator objects are filling
  // the matrix continuously.
  ThreadedCanvasManipulator *image_gen = NULL;
  
    printf("le code a été lancé\n");	
    image_gen = new pixel_defil(canvas); //C'est mon code ca
    image_gen->Start();
while(1);
	

}

