//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<cmath> //for pow function
using namespace std;
class Coord3D {    //class
public:
	double x; 
	double y;
	double z; 
};
double length(Coord3D *p)      //p is a pointer
{
	double o = sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));       //p-> is a member of x     and y and z 
	return o;
}
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
	double Point1= sqrt(pow(p1->x, 2) + pow(p1->y, 2)+pow(p1->z,2));    //p1 vector OP 
	double Point2= sqrt(pow(p2->x, 2) + pow(p2->y, 2) + pow(p2->z, 2));  //p2 vector OP
	if (Point1 > Point2)       //if point 1 is greater than point 2 that means point 1 is farther. 
	{
		return p1;
	}
	else
		return p2;
}
void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
	//double x1, y1, z1;
	ppos->x = ppos->x + pvel->x*dt;            // x prime=x+velocity * time
	ppos->y = ppos->y + pvel->y*dt;				// x prime=x+velocity * time
	ppos->z= ppos->z + pvel->z*dt;				// x prime=x+velocity * time
	
}
Coord3D* createCoord3D(double x, double y, double z)
{
	Coord3D* pvel = new Coord3D;                   //I can use both pvel or ppos
	pvel->x = x;
	pvel->y = y;
	pvel->z = z;
	return pvel;         //return each x y z as pvel and ppos        
}
void deleteCoord3D(Coord3D *p)
{
	delete p;    //deletes p from memory
}
int main()
{
		double x, y, z;
		cout << "Enter position: ";
		cin >> x >> y >> z;
		Coord3D *ppos = createCoord3D(x, y, z); //inpput x=10 we will get 10 from createCoord3D function.

		cout << "Enter velocity: ";
		cin >> x >> y >> z;
		Coord3D *pvel = createCoord3D(x, y, z);

		move(ppos, pvel, 10.0);

		cout << "Coordinates after 10 seconds: "
			<< (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

		deleteCoord3D(ppos); // release memory
		deleteCoord3D(pvel);
	
}