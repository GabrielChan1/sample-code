#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"
/*
TODO:
- Use the 'first_hit' function to calculate the nearest intersection if there is one
*/

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	int hit_id;
	if (first_hit(ray, min_t, triangles, hit_id, t, n)) {
		return true;
	}
	return false;
	////////////////////////////////////////////////////////////////////////////
}



