#include "Plane.h"
#include "Ray.h"
/*
TODO:
- Calculate 't' based on the formula given in the lecture slides
- If there is an intersection, calculate the surface normal at the point of intersection 

- ray.direction = s - e
- s = ray.origin + ray.direction
*/

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:

	// Calculate intermediate values
	double q = normal.transpose().dot(point);

	// Calculate 't1' using formula from lecture slides 
	double t1 = (q - normal.transpose().dot(ray.origin)) / (normal.transpose().dot(
		ray.direction));
	if (t1 < min_t) {
		return false;
	}
	t = t1;
	n = normal;
	return true;
	////////////////////////////////////////////////////////////////////////////
}

