#include "Sphere.h"
#include "Ray.h"
/*
TODO:
- Assign values 'a', 'b' and 'c' to forumlas from lecture slides
- Determine if there exists a valid value 't' such that the formula a*t^2 + b*t + c = 0
- If there is an intersection, calculate the surface normal at the point of intersection
- Normal is vector from the sphere's center to the point of intersection

From textbook:
- (d * d)t^2 + 2d * (e - c)t + (e - c) * (e - c) - r^2 = 0
- d = s - e = ray.direction - ray.origin
- s = ray.direction
- e = ray.origin

- Check if a ray is received with a t value greater than 0
*/

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:

	// Calculate intermediate values
	Eigen::Vector3d d = ray.direction - ray.origin;
	Eigen::Vector3d e = ray.origin;
	double a = d.dot(d);
	double b = (2 * d).dot(e - center);
	double c = (e - center).dot(e - center) - pow(radius, 2);

	double det = pow(b, 2) - 4 * a * c;
	// If the determinant is negative, then there is no intersection with the sphere
	if (det < 0) {
		return false;
	}

	// Calculate possible points of intersection using the quadratic formula
	double t1 = (-b + sqrt(det)) / (2 * a);
	double t2 = (-b - sqrt(det)) / (2 * a);

	// If 't1' is valid
	if (t1 >= min_t) {
		// If 't1' and 't2' are both valid
		if (t2 >= min_t) {	
			t = fmin(t1, t2);
		}
		// If only 't1' is valid
		else {
			t = t1;
		}
	}
	// If only 't2' is valid
	else if (t2 >= min_t) {
		t = t2;
	}
	// If neither 't1' or 't2' are valid
	else {
		return false;
	}
	n = center - (ray.origin + t * ray.direction);
	return true;
	////////////////////////////////////////////////////////////////////////////
}

