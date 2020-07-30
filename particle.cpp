//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<cmath>
using namespace std;
class Coord3D
{
public:
	double x, y, z;
};
class Particle
{
public:
	Coord3D dod; //holds x y z coord3d is amember of particle
	double vx, vy, vz;
};
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz)
{
	Particle*p = new Particle;
	p->dod.x = x;  //from coord3d
	p->dod.y = y; //from coord3d
	p->dod.z = z; //from coord3d
	p->vx = vx;  //from particle
	p->vy = vy; //from particle
	p->vz = vz; //from particle

	return p;
}
void setVelocity(Particle *p, double vx, double vy, double vz)
{
	p->vx = vx;  //from particle  
	p->vy = vy; //from particle
	p->vz = vz; //from particle
}
Coord3D getPosition(Particle *p)
{
	Coord3D dod;
	dod.x = p->dod.x; //from coord3d 
	dod.y = p->dod.y; //from coord3d 
	dod.z = p->dod.z; //from coord3d
	return dod;
}
void move(Particle *p, double dt)
{
	p->dod.x = p->dod.x + p->vx*dt;         //dod because we want to take x from coord3d; and take velocity from particle .
	p->dod.y = p->dod.y + p->vy*dt;
	p->dod.z = p->dod.z + p->vz*dt;

}
void deleteParticle(Particle *p)
{
	delete p;
}
int main() {
	// make new particle
	Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
	double time = 0.0;
	double dt = 0.1;
	while (time < 3.0) {
		// update its velocity
		setVelocity(p, 10.0 * time, 0.3, 0.1);

		// move the particle
		move(p, dt);
		time += dt;

		// reporting its coordinates
		cout << "Time: " << time << " \t";
		cout << "Position: "
			<< getPosition(p).x << ", "
			<< getPosition(p).y << ", "
			<< getPosition(p).z << endl;
	}
	// remove the particle, deallocating its memory
	deleteParticle(p);
}