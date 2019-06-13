#include "viewing_ray.h"
/*
TODO:
- Set 'ray.origin' to 'camera.e'
- Find values 'u' and 'v' to determine direction

- 'width' and 'height' = pixel width and height = n.x and n.y
- 'camera.width' and 'camera.height' = physical image width and height
*/

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
	////////////////////////////////////////////////////////////////////////////
	// Add your code here

	// Calculate 'u' and 'v' using formulas from lecture slides (according to the TA, the
	// positions of 'i' and 'j' in the lecture slides need to be swapped)
	double u = camera.width * ((j + (0.5)) / width) - (camera.width / 2.0);
	double v = camera.height * ((height - (i + 0.5)) / height) - (camera.height / 2.0);

	// Set origin of the ray to the origin of the camera
	ray.origin = camera.e;
	// Set direction of the ray using formula from the textbook
	ray.direction = camera.d * (-1.0) * camera.w + u * camera.u + v * camera.v;
	////////////////////////////////////////////////////////////////////////////
}

