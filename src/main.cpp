#include <iostream>
#include <string>
#include <fstream>

#include "trCamera.h"
#include "trPlane.h"
#include "trSphere.h"
#include "trImage.h"
#include "trBSDF.h"
#include "trLight.h"
#include "trTracer.h"
#include "trGeometry.h"

using namespace tr;

int main ()
{
    Point3f eye (0,0,0),atl(0,0,-1);
    Vector3f up(0,1,0);
    Camera c(eye,atl,up,60.0f,Vector2i(512,512),2.5f,0.0f);

    Spectrum white (0.75,0.75,0.75);
    Spectrum black (0,0,0);
    Spectrum red (0.75,0.25,0.25);
    Spectrum green (0.25,0.75,0.25);
    Spectrum blue (0.25,0.25,0.75);

    Plane plLeft (Point3f(-1.1,0,0),Normal3f(1,0,0));
    Plane plRight (Point3f(1.1,0,0),Normal3f(-1,0,0));
    Plane plBottom (Point3f(0,-1,0),Normal3f(0,1,0));
    Plane plTop (Point3f(0,1,0),Normal3f(0,-1,0));
    Plane plBack (Point3f(0,0,-3.9),Normal3f(0,0,1));
    Plane plFront (Point3f(0,0,3.9),Normal3f(0,0,-1));
    Sphere sp0 (Point3f(-0.45,-0.6,-3),0.4f);
    Sphere sp1 (Point3f(0.5,-0.65,-2.5),0.35f);
    Sphere spl0 (Point3f(0,101.0f,-2.5),100.0005f);

    PointLight pl0 (Spectrum(5,5,5),Point3f(0,0.7,-2.5));
    SpotLight sl0 (Spectrum(1,1,1),Point3f(0,0.7,-2.5),Vector3f(0,-1,0),65.0f,60.0f);
    AreaLight al0 (Spectrum(70,70,70),&spl0);
    std::vector<Light *> lve;
    lve.push_back(&pl0);
    //lve.push_back(&sl0);
    //lve.push_back(&al0);

    DiffuseBSDF whiteD (white);
    DiffuseBSDF blackD (white);
    DiffuseBSDF redD (red);
    DiffuseBSDF blueD (blue);
    DiffuseBSDF greenD (green);
    ReflectBSDF reflect (Spectrum(1,1,1));
    RefractBSDF refract (1.3);

    Geometry gpl0(&redD,&plLeft);
    Geometry gpl1(&blueD,&plRight);
    Geometry gpl2(&whiteD,&plBottom);
    Geometry gpl3(&whiteD,&plTop);
    Geometry gpl4(&greenD,&plBack);
    Geometry gpl5(&blackD,&plFront);
    Geometry gsp0(&reflect,&sp0);
    Geometry gsp1(&refract,&sp1);
    //Area light
    Geometry gsp2(&reflect,&spl0,&al0);
    std::vector<Geometry *> gve;
    gve.push_back(&gpl0);
    gve.push_back(&gpl1);
    gve.push_back(&gpl2);
    gve.push_back(&gpl3);
    gve.push_back(&gpl4);
    gve.push_back(&gpl5);
    gve.push_back(&gsp0);
    gve.push_back(&gsp1);
    //gve.push_back(&gsp2);

    Tracer tracer(512,512,gve,lve,c);
    tracer.render(std::string("output"));

    return 0;
}
