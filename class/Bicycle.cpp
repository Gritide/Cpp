//Dogukan Celik
//Dogukan.Celik89@myhunter.cuny.edu
#include<iostream>
#include<string>
#include<stdlib.h>
#include"Bicycle.h"
using namespace std;
Bicycle::Bicycle()
{
	curr_speed_ = 0;
	curr_direction_ = 0;                                // 0 <= direction <= 360 in which the caller is traveling                    
	seat_height_=10;
	distance_traveled_ =0;
	curr_pedal_intensity_ = bike_details::pedalling_intensity::NONE;
	int z = rand();
	b_type_ = bike_details::bike_type(rand()%3);
}


Bicycle::Bicycle(int kind_of_bike)
{
	b_type_= bike_details::bike_type (kind_of_bike);
	curr_pedal_intensity_ = (bike_details::pedalling_intensity) (0);
	curr_direction_ = 0;                                // 0 <= direction <= 360 in which the caller is traveling
	seat_height_ = 10;
}
void Bicycle::updateSpeed()
{
	if (curr_pedal_intensity_ == 0)
	{
		curr_speed_ = 0;
	}
	else
		curr_speed_ = ((curr_pedal_intensity_) / 8)*(b_type_)+((curr_pedal_intensity_) / 8 + (b_type_));

}
float Bicycle::ride(float duration)
{
	distance_traveled_ = duration;
	distance_traveled_ = duration / curr_speed_;
	return distance_traveled_;
}


void Bicycle::changeSeatHeight(int inches)
{
	if (inches >= 36)
	{
		seat_height_ = 36;
	}
	else if (inches <=0)
	{
		seat_height_ = 0;
	}
	else
	{
		seat_height_ = inches;
	}
}

/**
if the current intensity is not HIGH increase it by one level and call updateSpeed()
*/
void Bicycle::pedal()
{
		if (curr_pedal_intensity_ == bike_details::pedalling_intensity::NONE)
		{
			curr_pedal_intensity_ = bike_details::pedalling_intensity::LOW;
	
		}
		else if (curr_pedal_intensity_ == bike_details::pedalling_intensity::LOW)
		{
			curr_pedal_intensity_ = bike_details::pedalling_intensity::MEDIUM;

		}

		else if (curr_pedal_intensity_ == bike_details::pedalling_intensity::MEDIUM)
		{
			curr_pedal_intensity_ = bike_details::pedalling_intensity::HIGH;

		}
		updateSpeed();
}

/**
if the current intensity is not NONE decrease it by one level and call updateSpeed()
*/
void Bicycle::brake()
{
		if (curr_pedal_intensity_ == bike_details::pedalling_intensity::HIGH)
		{
			curr_pedal_intensity_ = bike_details::pedalling_intensity::MEDIUM;
		}
		else if (curr_pedal_intensity_ == bike_details::pedalling_intensity::MEDIUM)
		{		
			curr_pedal_intensity_ = bike_details::pedalling_intensity::LOW;
		}
		else if (curr_pedal_intensity_ == bike_details::pedalling_intensity::LOW)
		{
			curr_pedal_intensity_ = bike_details::pedalling_intensity::NONE;
		}
		updateSpeed();
}

/**
updates direction_
@param degrees: -360 <= degrees <= 360, and if the user enters a number outside of these
bounds adjust @param degrees to be within this range
*/
void Bicycle::turn(float degrees)
{
	if (degrees >= -360 && degrees <= 360)
	{
		curr_direction_ += degrees;
	}
	else if (degrees<-360)
	{
		degrees = -360 - degrees;

	}
	else
	{
		degrees = degrees - 360;
	}
}

/**
return the string that corresponds to the curr_direction_ that the caller faces
relative to a cartesian plane; assume that the caller is at position (0,0),
the degree measure of (1, 0) is 0 degrees, and the degree measure of (-1, 0) is 180 degrees

"North" == 90
0 < "Northeast" < 90
"East" == 0
"Southeast > 270
"South" == 270
180 < "Southwest < 270
"West" == 180
90 < "Northwest" < 180
*/
string Bicycle::getDirection()
{
	if (curr_direction_ == 90)
	{
		return "North";
	}
	else if (curr_direction_>0 && curr_direction_<90)
	{
		return "Northeast";
	}
	else if (curr_direction_ == 0 || curr_direction_ == 360)
	{
		return "East";
	}
	else if (curr_direction_ > 270 && curr_direction_<360)
	{
		return "Southeast";
	}
	else if (curr_direction_ == 270)
	{
		return "South";
	}
	else if (curr_direction_ >180 && curr_direction_<270)
	{
		return "Southwest";
	}
	else if (curr_direction_ == 180)
	{
		return "West";
	}
	else if (curr_direction_ >90 && curr_direction_<180)
	{
		return "Northwest";
	}
	else
	{
		return "Wrong Input";
	}
}

/* Getter: b_type_ */
string Bicycle::getBikeType()
{
	if (b_type_ == bike_details::bike_type::BMX)
		return "BMX";
	else if (b_type_ == bike_details::bike_type::MOUNTAIN)
		return "MOUNTAIN";
	else if (b_type_ == bike_details::bike_type::TOURING)
		return "TOURING";
	else
		return "ROAD";
}

/* Getter: seat_height_ in inches */
int Bicycle::getSeatHeight()
{
	changeSeatHeight(seat_height_);
	return seat_height_;
}

/* Getter: curr_speed_ in miles per hour */
float Bicycle::getSpeed()
{
	updateSpeed();
	return curr_speed_;
}

/* Getter: distance_traveled_ in miles */
float Bicycle::getDistanceTraveled()
{
	ride(distance_traveled_);
	return distance_traveled_;
}
/* Getter: curr_pedal_intensity_ */
string Bicycle::getIntensity()
{

	if (curr_pedal_intensity_ == bike_details::pedalling_intensity::HIGH)
		return "High";
	else if (curr_pedal_intensity_ == bike_details::pedalling_intensity::MEDIUM)
		return "Medium";
	else if (curr_pedal_intensity_ == bike_details::pedalling_intensity::LOW)
		return "Low";
	else
		return"None";
}
int main()
{
	Bicycle b;
	cout << b.getSeatHeight() << " Seat Height" << endl;
	//cout << b.getDirection() << endl;
	//cout << b.getSpeed() << endl;
	//cout << b.getDistanceTraveled() <<"travel"<< endl;
	//cout << b.getBikeType() << endl;
	//cout << b.getDistanceTraveled() << endl;

	//b.pedal();
	//b.brake();
	//b.turn(540);
	//cout << b.getIntensity() << endl;
	//cout << "You are riding at " << b.getSpeed() << endl
	//cout << b.getSpeed() << endl;
	//b.brake();
	//cout << b.getSpeed() << endl;
	//b.brake();
	//cout << b.getSpeed() << endl;
	//b.brake();
	//cout << b.getSpeed() << endl;
	//b.brake();


}


