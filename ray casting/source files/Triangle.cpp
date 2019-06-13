#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
/*
TODO:
- Calculate 't' based on the formula given in the lecture slides
- If there is an intersection, calculate the surface normal at the point of intersection
- Form two vectors from the triangle corners and cross product them to get normal

Cramers rule from textbook:
- A = a.x - b.x
- B = a.y - b.y
- C = a.z - b.z
- D = a.x - c.x
- E = a.y - c.y
- F = a.z - c.z
- G = d.x
- H = d.y
- I = d.z
- J = a.x - e.x
- K = a.y - e.y
- L = a.z - e.z
- d = s - e = ray.direction - ray.origin
- s = ray.direction
- e = ray.origin
*/

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:

	// Create some shorthand vector and double intermediate values
	Eigen::Vector3d a = std::get<0>(corners);
	Eigen::Vector3d b = std::get<1>(corners);
	Eigen::Vector3d c = std::get<2>(corners);
	Eigen::Vector3d d = ray.direction - ray.origin;
	Eigen::Vector3d e = ray.origin;
	double A = a(0) - b(0);
	double B = a(1) - b(1);
	double C = a(2) - b(2);
	double D = a(0) - c(0);
	double E = a(1) - c(1);
	double F = a(2) - c(2);
	double G = d(0);
	double H = d(1);
	double I = d(2);
	double J = a(0) - e(0);
	double K = a(1) - e(1);
	double L = a(2) - e(2);

	// Intermediate value for equation from textbook
	double M = A * (E * I - H * F) + B * (G * F - D * I) + C * (D * H - E * G);

	// Calculate values for 't', 'beta' and 'gamma'
	double t1 = (F * (A * K - J * B) + E * (J * C - A * L) + D * (B * L - K * C)) / M;
	if (t1 < min_t) {
		return false;
	}
	double gamma = (I * (A * K - J * B) + H * (J * C - A * L) + G * (B * L - K * C)) / M;
	if (gamma < 0 || gamma > 1) {
		return false;
	}
	double beta = (J * (E * I - H * F) + K * (G * F - D * I) + L * (D * H - E * G)) / M;
	if (beta < 0 || beta > 1 - gamma) {
		return false;
	}

	t = t1;
	// Form two vectors from the corners by subtracting them. Then set the cross product as 
	// the normal
	n = (a - b).cross(a - c);
	return true;
	
	////////////////////////////////////////////////////////////////////////////
}


