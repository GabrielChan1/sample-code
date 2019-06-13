#include "PointLight.h"
/*
TODO:
- Assign 'p - q' to 'd'
*/

void PointLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
	////////////////////////////////////////////////////////////////////////////
	// Add your code here:

	// Subtract the query point from the origin point of the light to get a directional
	// vector
	d = (p - q).normalized();

	// Square root the dot product of 'd' by itself to get the Euclidean length
	max_t = sqrt(d.dot(d));
	////////////////////////////////////////////////////////////////////////////
}