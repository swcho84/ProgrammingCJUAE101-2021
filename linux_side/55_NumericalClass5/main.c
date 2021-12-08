#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define TMAX   		0.2
#define DT			  0.02
#define X0				0.0
#define Y0				0.0
#define VX0				1.0
#define VY0				1.0
#define GRAV			9.8

typedef struct 
{
	double x;
	double y;
} Pos;

typedef struct 
{
	double vx;
	double vy;
} Vel;

// system model, projectile motion
Vel FuncVel(double t)
{
	Vel result;
	result.vx = (VX0);
	result.vy = (VY0) - (GRAV) * (t);
	return result;	
}

// calculating the exact solution
Pos ExactFuncPos(double t)
{
	Pos result;
	result.x = (X0) + (VX0) * (t);
	result.y = (Y0) + (VY0) * (t) - (0.5) * (GRAV) * (t * t);
	return result;
}

// calculating the Euler integration
Pos EulerInteg(Pos inputPos, Vel inputVel, double dt)
{
	Pos result;
	result.x = inputPos.x + (inputVel.vx) * (dt);
	result.y = inputPos.y + (inputVel.vy) * (dt);
	return result;	
}

// calculating the Runge-Kutta 4th order integration
Pos Rk4Integ(Pos inputPos, double t, double dt)
{
	Pos result;
	double k1x = FuncVel(t).vx;
	double k2x = (FuncVel(t + dt * 0.5).vx) + (dt * 0.5 * k1x);
	double k3x = (FuncVel(t + dt * 0.5).vx) + (dt * 0.5 * k2x);
	double k4x = (FuncVel(t + dt).vx) + (dt * k3x);
	double k1y = FuncVel(t).vy;
	double k2y = (FuncVel(t + dt * 0.5).vy) + (dt * 0.5 * k1y);
	double k3y = (FuncVel(t + dt * 0.5).vy) + (dt * 0.5 * k2y);
	double k4y = (FuncVel(t + dt).vy) + (dt * k3y);	
	result.x = inputPos.x + (k1x + (2.0 * k2x) + (2.0 * k3x) + k4x) * ((dt) / (6.0));
	result.y = inputPos.y + (k1y + (2.0 * k2y) + (2.0 * k3y) + k4y) * ((dt) / (6.0));
	return result;	
}

int main()
{
  // preparing time data
	const int nTotal = ((TMAX)/(DT) + 1);
  double dTimestate[nTotal] = {};
  for (unsigned int i = 0; i < nTotal; i++)
    dTimestate[i + 1] = dTimestate[i] + DT;	
 
	// calculating the exact solution
  Pos* exactPos = (Pos*)(malloc(sizeof(Pos) * nTotal));
	exactPos[0].x = X0;
	exactPos[0].y = Y0;
  for (unsigned int i = 0; i < nTotal; i++)
    exactPos[i] = ExactFuncPos(dTimestate[i]);

	// calculating the Euler integration
  Pos* eulerIntegPos = (Pos*)(malloc(sizeof(Pos) * nTotal));
	eulerIntegPos[0].x = X0;
	eulerIntegPos[0].y = Y0;
  for (unsigned int i = 0; i < nTotal; i++)
		eulerIntegPos[i + 1] = EulerInteg(eulerIntegPos[i], FuncVel(dTimestate[i]), DT);

	// calculating the Runge-Kutta 4th order integration
  Pos* rk4IntegPos = (Pos*)(malloc(sizeof(Pos) * nTotal));
	rk4IntegPos[0].x = X0;
	rk4IntegPos[0].y = Y0;
  for (unsigned int i = 0; i < nTotal; i++)
		rk4IntegPos[i + 1] = Rk4Integ(rk4IntegPos[i], dTimestate[i], DT);		

	// for debugging
  for (unsigned int i = 0; i < nTotal; i++)
	{
    printf("[%d](exactPos,eulerIntegPos,rk4IntegPos):((%.4lf,%.4lf),(%.4lf,%.4lf),(%.4lf,%.4lf))\n", 
						i, exactPos[i].x, exactPos[i].y, 
							 eulerIntegPos[i].x, eulerIntegPos[i].y,
							 rk4IntegPos[i].x, rk4IntegPos[i].y);
	}
    
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}