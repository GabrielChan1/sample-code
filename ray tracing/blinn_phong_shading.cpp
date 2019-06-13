#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>
/*
TODO:
- Use the 'first_hit' function to determine which lights reach the point of intersection
	(create a ray from object to light and determine if the ray hits an object instead)
- Calculate Blinn-Phong shading at the given intersection for each light using equation 4.4 
from textbook (k.a, k.d and k.s are part of the object)
*/

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:

	// Intermediate variables to use 'first_hit' and 'Light.direction' functions
	Ray r;
	Eigen::Vector3d d, first_hit_n;
	double light_direction_t, first_hit_t;
	int hit_id1;
	r.origin = ray.origin + t * ray.direction;

	// Ambient light value;
	double I_a = 0.1;

	// Intermediate values for calculating blinn-phong shading
	Eigen::Vector3d I_i;			// Light intensity
	Eigen::Vector3d l_i;			// Light direction
	Eigen::Vector3d h_i;			// Light half vector
	
	Eigen::Vector3d v = -ray.direction.normalized();	// Viewing ray direction

	Eigen::Vector3d shading = Eigen::Vector3d(0.0, 0.0, 0.0);	// Sum of specular and diffuse intensities
	Eigen::Vector3d K_a = (*(*objects[hit_id]).material).ka;	// Ambient coefficient
	Eigen::Vector3d K_d = (*(*objects[hit_id]).material).kd;	// Diffuse coefficient
	Eigen::Vector3d K_s = (*(*objects[hit_id]).material).ks;	// Specular coefficient
	double p = (*(*objects[hit_id]).material).phong_exponent;	// Phong exponent

	// For each light, calculate the blinn-phong shading, if the light reaches the surface, 
	// using the formula from the textbook
	for (int i = 0; i < lights.size(); i++) {
		(*lights[i]).direction(r.origin, d, light_direction_t);
		r.direction = d;
		// If no objects block the intersection point from the light
		if (!first_hit(r, 0.00001, objects, hit_id1, first_hit_t, first_hit_n)) {
			// Calculate intermediate values
			I_i = (*lights[i]).I;
			l_i = d;
			h_i = (v + d) / sqrt((v + d).dot(v + d));

			// Calculate and add specular and diffuse intensities for each colour
			shading[0] += K_d[0] * I_i[0] * fmax(0, n.dot(l_i)) + K_s[0] * I_i[0] * pow(fmax(0, n.dot(h_i)), p);
			shading[1] += K_d[1] * I_i[1] * fmax(0, n.dot(l_i)) + K_s[1] * I_i[1] * pow(fmax(0, n.dot(h_i)), p);
			shading[2] += K_d[2] * I_i[2] * fmax(0, n.dot(l_i)) + K_s[2] * I_i[2] * pow(fmax(0, n.dot(h_i)), p);
		}
	}
	Eigen::Vector3d L = K_a * I_a + shading;	
	
	// "Clamp" the colour values
	if (L[0] > 1.0) {
		L[0] = 1.0;
	}
	if (L[1] > 1.0) {
		L[1] = 1.0;
	}
	if (L[2] > 1.0) {
		L[2] = 1.0;
	}
	
	return L;
	////////////////////////////////////////////////////////////////////////////
}