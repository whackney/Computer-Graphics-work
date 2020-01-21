#include "PPM.h"
#include <array>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct pixel {
  int r;
  int g;
  int b;
};

int width;
int height;
int maxPixel;
pixel pic[width][height];


// Constructor loads a filename with the .ppm extension
PPM::PPM(std::string fileName){
    // TODO:    Load and parse a ppm to get its pixel
    //          data stored properly.

  std::ifstream inFile;
  inFile.open(fileName);
  if(fileName.is_open()) {
    int counter = 0;
    int atPixel = 0;
    std::string line;
    while(getline(inFile,line)){
      if(counter == 2) {
        std::string w;
        std::string h;
        int atWidth = 0;
        int atHeight = 0;
        int atRGB = 0;
        int i = 0;

        while (i < line.length()) {
          if (line.at(i) == ' ') {
            i++;
            break;
          }
          else {
            w.append(line.at(i));
            i++;
          }
        }

        while (i < line.length()) {
          h.append(line.at(i));
          i++;
        }

        stringstream wid(w);
        stringstream len(h);
        wid >> width;
        len >> height;
        counter++;
      }

      else if(counter == 3 ) {
        int i = 0;
        std::string m
        while (i < line.length()) {
          m.append(line.at(i));
        }

        stringstream max(m);
        max >> maxPixel;
        counter++;
      }

      else if(counter > 3) {
        pixel p;
        for(int i = 0; i < 3; i++) {
          if(i == 0) {
            String red;
            red.append(line);
            stringstream re(red);
            re >> p.r;
          }

          if(i == 1) {
            String green;
            green.append(getline(inFile, line));
            stringstream gr(green);
            fr >> p.g;
          }

          if(i == 2) {
            String blue;
            blue.append(getline(inFile, line));
            stringstream bl(blue);
            bl >> p.b;
          }
        }
        counter++
      }

      else{
        counter++;
      }
    }
  inFile.close();
}

// Destructor clears any memory that has been allocated
PPM::~PPM(){
}

// Saves a PPM Image to a new file.
void PPM::savePPM(std::string outputFileName){
    // TODO: Save a PPM image to disk
    std::ofstream outFile;
    outFile.open(outputFileName);

    outFile << "P3" << std::endl;
    outFile << width << " " << height << std::endl;
    for(pixel x : pic) {
      outfile << x.r << std::endl;
      outfile << x.g << std::endl;
      outfile << x.b << std::endl;
    }

    outFile.close();

    return 0;
}

// Darken subtracts 50 from each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be less than
// 0 in a ppm.
void PPM::darken(){
    // TODO: Output a 'filtered' PPM image.
    for(pixel x : pic) {
      x.r = x.r-50;
      x.g = x.g-50;
      x.b - x.b-50;

      for (int i = 0; i < 3; i++) {
        if(x.r  < 0) {
          x.r = 0;
        }

        else if(x.g < 0) {
          x.g = 0;
        }

        else if(x.b < 0) {
          x.b = 0;
        }
      }
    }
}

// Sets a pixel to a specific R,G,B value
void PPM::setPixel(int x, int y, int R, int G, int B){
    pic[x][y].r = R;
    pic[x][y].g = G;
    pic[x][y].b = B;

}
