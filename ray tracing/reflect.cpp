#include <Eigen/Core>
/*
TODO:
- Calculate and return the outgoing vector using equation 4.5 from the textboook
*/

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	return in - 2 * (in.dot(n)) * n;
	////////////////////////////////////////////////////////////////////////////
}
