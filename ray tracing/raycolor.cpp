#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"
/*
TODO:
- Use the 'first_hit' function to search along the given ray for intersections
- Calculate the blinn-phong shading if there is a hit
- Recursively call 'raycolor' for each time the ray bounces off an object
*/

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:

	// Set a maximum number of times this function may be called recursively
	int max_recursive_calls = 10;
	if (num_recursive_calls >= max_recursive_calls) {
		return false;
	}

	// Intermediate variables for using 'first_hit' and 'blinn_phong_shading' functions
	int hit_id;
	double t;
	Eigen::Vector3d C, C_reflect, n;

	// If the ray hits an object, calculate the blinn phong shading at the intersection
	if (first_hit(ray, min_t, objects, hit_id, t, n)) {
		C = blinn_phong_shading(ray, hit_id, t, n, objects, lights);	// Blinn-Phong shading
		Eigen::Vector3d K_m = (*(*objects[hit_id]).material).km;		// Mirror colour
		
		// Create a new ray to recursively call 'raycolor'
		Ray r;
		r.origin = ray.origin + t * ray.direction;
		r.direction = reflect(ray.direction, n);
		
		// Recursively call 'raycolor' and add the intensities to 'rgb'
		raycolor(r, min_t, objects, lights, num_recursive_calls + 1, C_reflect);
		
		rgb = C + (C_reflect.array() * K_m.array()).matrix();
		
		// "Clamp" the colour values
		if (rgb[0] > 1.0) {
			rgb[0] = 1.0;
		}
		if (rgb[1] > 1.0) {
			rgb[1] = 1.0;
		}
		if (rgb[2] > 1.0) {
			rgb[2] = 1.0;
		}
		
		return true;
	}
	return false;
	////////////////////////////////////////////////////////////////////////////
}

