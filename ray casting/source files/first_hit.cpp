#include "first_hit.h"
/*
TODO:
- Check each of the objects in 'objects' for intersection using the methods from other files and
return the 'id', 't' and 'n' of the closest object intersected if there is any intersection
*/

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	int id;
	double t1;
	Eigen::Vector3d n2, n1;
	double min_t1 = std::numeric_limits<double>::infinity();
	bool hit = false;
	// For each object in the 'objects' array, apply its respective intersect method
	for (int i = 0; i < objects.size(); i++) {
		// If there is an intersection
		if ((*objects[i]).intersect(ray, min_t, t1, n2)) {
			hit = true;
			// Update the current closest intersection
			if (t1 < min_t1) {
				min_t1 = t1;
				id = i;
				n1 = n2;
			}
		}
	}
	// Return the closest intersection if there is one
	if (hit) {
		hit_id = id;
		t = t1;
		n = n1;
		return true;
	}
	return false;
	////////////////////////////////////////////////////////////////////////////
}

