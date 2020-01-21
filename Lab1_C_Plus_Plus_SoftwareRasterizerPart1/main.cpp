/** @file main.cpp
 *  @brief Entry point into our program.
 *
 *  Welcome to the Great Looking Software Render
 *  code base (Yes, I needed something with a gl prefix).
 *
 *  This is where you will implement your graphics API.
 *
 *  Compile on the terminal with:
 *
 *  clang++ -std=c++11 main.cpp -o main
 *
 *  @author Mike Shah
 *  @bug No known bugs.
 */

// Load our libraries
#include <iostream>

// Some define values
#define WINDOW_HEIGHT 320
#define WINDOW_WIDTH 320

// C++ Standard Libraries
#include <iostream>
#include <algorithm>

// User libraries
#include "GL.h"
#include "Color.h"
#include "TGA.h"
#include "Maths.h"

// Create a canvas to draw on.
TGA canvas(WINDOW_WIDTH,WINDOW_HEIGHT);


// Implementation of Bresenham's Line Algorithm
// The input to this algorithm is two points and a color
// This algorithm will then modify a canvas (i.e. image)
// filling in the appropriate colors.
void drawLine(Vec2 v0, Vec2 v1, TGA& image, ColorRGB c){
    bool steep = false;
    if(std::abs(v0.x-v1.x)<std::abs(v0.y-v1.y)){
        // If the line is steep we want to transpose the image.
        std::swap(v0.x,v0.y);
        std::swap(v1.x,v1.y);
        steep = true;
    }
    if(v0.x>v1.x){  // make it left-to-right
        std::swap(v0.x, v1.x);
        std::swap(v0.y, v1.y);
    }
    for(int x = v0.x; x <= v1.x; ++x){
        float t = (x-v0.x)/(float)(v1.x-v0.x);
        int y = v0.y*(1.0f-t) + v1.y*t;
        if(steep){
            canvas.setPixelColor(y,x,c);
        }else{
            canvas.setPixelColor(x,y,c);
        }
    }
}

void fillBottomFlatTriangle(Vec2 v0, Vec2 v1, Vec2 v2, TGA& image, ColorRGB c){
  float invslope1 = (v1.x - v0.x) / (v1.y - v0.y);
  float invslope2 = (v2.x - v0.x) / (v2.y - v0.y);

  float curx1 = v0.x;
  float curx2 = v0.x;

  for (int scanlineY = v0.y; scanlineY <= v1.y; scanlineY++)
  {
    Vec2 left = {(int)curx1, scanlineY};
    Vec2 right = {(int)curx2, scanlineY};
    drawLine(left, right, image, c);
    curx1 += invslope1;
    curx2 += invslope2;
  }
}

void fillTopFlatTriangle(Vec2 v0, Vec2 v1, Vec2 v2, TGA& image, ColorRGB c){
  float invslope1 = (v2.x - v0.x) / (v2.y - v0.y);
  float invslope2 = (v2.x - v1.x) / (v2.y - v1.y);

  float curx1 = v2.x;
  float curx2 = v2.x;

  for (int scanlineY = v2.y; scanlineY > v0.y; scanlineY--)
  {
    Vec2 left = {(int)curx1, scanlineY};
    Vec2 right = {(int)curx2, scanlineY};
    drawLine(left, right, image, c);
    curx1 -= invslope1;
    curx2 -= invslope2;
  }
}

void drawTriangle(Vec2 v0, Vec2 v1, Vec2 v2, TGA& image, ColorRGB c){
  if (v1.y == v2.y){
    fillBottomFlatTriangle(v0, v1, v2, image, c);
  }

  else if (v0.y == v1.y){
    fillTopFlatTriangle(v0, v1, v2, image, c);
  }

  else {
    Vec2 newVector = {
      (int)(v0.x + ((float)(v1.y - v0.y) / (float)(v2.y - v0.y))
      * (v2.x - v0.x)), v1.y
    };

    fillBottomFlatTriangle(v0, v1, newVector, image, c);
    fillTopFlatTriangle(v1, newVector, v2, image, c);
  }
}

// Draw a triangle
void triangle(Vec2 v0, Vec2 v1, Vec2 v2,TGA& image, ColorRGB c){
    if(glFillMode==LINE){
        drawLine(v0,v1,image,c);
        drawLine(v1,v2,image,c);
        drawLine(v2,v0,image,c);
    }
    // TODO: Draw a filled triangle
    Vec2 points[] = {v0, v1, v2};
    int n = sizeof(points)/sizeof(points[0]);
    std::sort(points, points+n, [](Vec2 a, Vec2 b){
      return a.y < b.y;
    });
    drawTriangle(points[0], points[1], points[2], image, c);
}



// Main
int main(){

    // A sample of color(s) to play with
    ColorRGB red;
    red.r = 255; red.g = 0; red.b = 0;


    // Points for our Line
    Vec2 line[2] = {Vec2(0,0), Vec2(100,100)};

    // Set the fill mode
    glPolygonMode(FILL);

    // Draw a line
    drawLine(line[0],line[1],canvas,red);

    // Data for our triangle
    Vec2 tri[3] = {Vec2(160,60),Vec2(150,10),Vec2(75,190)};
    Vec2 tri1[3] = {Vec2(300,20),Vec2(500,40),Vec2(100,40)};

    // Draw a triangle
    triangle(tri[0],tri[1],tri[2],canvas,red);
    triangle(tri1[0], tri1[1], tri1[2], canvas, red);


    // Output the final image
    canvas.outputTGAImage("graphics_lab2.ppm");

    return 0;
}
