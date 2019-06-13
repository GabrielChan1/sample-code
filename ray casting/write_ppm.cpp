#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code from computer-graphics-raster-images or email
	// jacobson@cs.toronto.edu for correct code.
	std::ofstream file;
	file.open(filename);
	// Ensure file is open
	if (file.is_open()) {
		// If the image is rgb, write three elements at a time
		if (num_channels == 3) {
			file << "P3\n";
			file << width << " " << height << "\n";
			file << "255\n";
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width * 3; j += 3) {
					file << (int)data[i * width * 3 + j] << " ";
					file << (int)data[i * width * 3 + j + 1] << " ";
					file << (int)data[i * width * 3 + j + 2] << " ";
				}
				file << "\n";
			}
		}
		// If the image is grayscale, just write one image at a time
		else if (num_channels == 1) {
			file << "P2\n";
			file << width << " " << height << "\n";
			file << "255\n";
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					file << (int)data[i * width + j] << " ";
				}
				file << "\n";
			}
		}
		file.close();
		return true;
	}
	else {
		// Return false if the file could not be opened
		return false;
	}
	////////////////////////////////////////////////////////////////////////////
}
