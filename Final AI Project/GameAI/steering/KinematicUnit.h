#pragma once

#include "Kinematic.h"
#include "Steering.h"

/*KinematicUnit - a unit that is derived from the Kinematic class.  Adds behaviors and max speeds and a current Steering.

Dean Lawson
Champlain College
2011
*/

//forward declarations
class Sprite;
class GraphicsBuffer;
class BlendedSteering;
class CollisionAvoidance;
class Node;
class Graph;
extern Steering gNullSteering;//global object - can point to it for a "NULL" Steering

//minmimum forward speed a unit has to have inorder to rotate 
//(keeps unit from spinning in place after stopping
const float MIN_VELOCITY_TO_TURN_SQUARED = 1.0f;

class KinematicUnit: public Kinematic
{
public:
	KinematicUnit( Sprite* pSprite, const Vector2D& position, float orientation, const Vector2D& velocity, float rotationVel, int level, float maxVelocity = 1.0f, float maxAcceleration = 1.0f );
	~KinematicUnit();

	//getters and setters
	void setTarget( const Vector2D& target ) { mTarget = target; };
	const Vector2D& getPosition() const { return mPosition; };
   void setPosition( Vector2D newPos) { mPosition = newPos; };
	float getMaxVelocity() const { return mMaxVelocity; };
	Vector2D getVelocity() const { return mVelocity; };
	float getMaxAcceleration() const { return mMaxAcceleration; };
	void setVelocity( const Vector2D& velocity ){ mVelocity = velocity; };
	void setMaxVelocity(float maxVelocity) { mMaxVelocity = maxVelocity; };
	virtual void setNewOrientation();//face the direction you are moving
	Steering* getSteering() { return mpCurrentSteering; };
	Node*  getLastNode() { return mLastNode; };
	//draw yourself to the indicated buffer
	void draw( GraphicsBuffer* pBuffer );
	//move according to the current velocities and update velocities based on current Steering
	void update(float time);

    void policeSteering();
	void setSteering(Steering* pSteering);
	void updateGridPosition();



	int mCurrentLevel;

private:
	Sprite* mpSprite;
	Steering* mpCurrentSteering;
	Vector2D mTarget;//used only for Kinematic seek and arrive
	float mMaxVelocity;
	float mMaxAcceleration;
	Graph* mpGraph;
	Node* mLastNode;
	

};