#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * PI / 180);
}

double	rad_to_deg(double rad)
{
	return (rad * 180 / PI);
}

double	normalise_angle(double degree)
{
	if (degree < 0)
		degree += 360;
	else if(degree > 360)
		degree -= 360;
	return degree;
}
