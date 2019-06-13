#include "DirectionalLight.h"
#include <limits>
/*
TODO:
- Assign parameter 'd' to the global variable 'd'
*/

void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
	////////////////////////////////////////////////////////////////////////////
	// Add your code here

	// A directional light contains its own direction. We just have to assign it
	d = -(this->d).normalized();

	max_t = std::numeric_limits<double>::infinity();
	////////////////////////////////////////////////////////////////////////////
}

