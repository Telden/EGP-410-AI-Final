#ifndef RAYCAST_H
#define RAYCAST_H

#include "Vector2D.h"
#include <vector>

class KinematicUnit;
class WallUnit;
struct CastWall;

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// math and idea for algorithm used in this class found here: https://stackoverflow.com/questions/99353/how-to-test-if-a-line-segment-intersects-an-axis-aligned-rectange-in-2d //
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

const int NUMBER_OF_VERTICES_ON_A_RECTANGLE_LOL = 4;

class Raycast
{
   private :
      // the start and end points of the ray
      Vector2D startRay, endRay;

      // an ongoing list of walls and information regarding their intersection
      std::vector<CastWall> walls;

   public :
      Raycast();
      ~Raycast();

      bool doIt();
      float result(Vector2D wall);

      void setStartRay(Vector2D vec) { startRay = vec; };
      void setEndRay(Vector2D vec) { endRay = vec; };
};

struct CastWall
{
	// the unit
	WallUnit* unit;

	// the result of the result function
	float intersects;

   CastWall(WallUnit* wall)
   {
      unit = wall;
      intersects = 0;
   }
};
#endif