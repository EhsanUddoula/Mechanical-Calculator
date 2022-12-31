#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<iostream>

using namespace std;
SDL_Texture* img[120];
SDL_Rect img_rect[50];

void Load_image(SDL_Renderer* render);

void Load_image(SDL_Renderer* render){

    SDL_Surface* surface=NULL;
    //inclined Plane problem
    surface=IMG_Load("Image/inclined.png");
    img[0]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[0]={455,10,350,300};
    SDL_FreeSurface(surface);
    surface=NULL;
    //impulse problem
    surface=IMG_Load("Image/impulsive1.png");
    img[1]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[1]={455,10,350,300};
    SDL_FreeSurface(surface);
    //pulley problem
    surface=IMG_Load("Image/pulley.png");
    img[2]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[2]={455,50,350,300};
    SDL_FreeSurface(surface);
    //rotational motion
    surface=IMG_Load("Image/rotational motion.png");
    img[3]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[3]={455,10,350,300};
    SDL_FreeSurface(surface);
    //blue ring
    surface=IMG_Load("Image/ring blue.png");
    img[4]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //centerwhite
    surface=IMG_Load("Image/center white.png");
    img[5]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //tank
    surface=IMG_Load("Image/tank.png");
    img[12]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //underwater
    surface=IMG_Load("Image/underwater.png");
    img[14]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //bubble
    surface=IMG_Load("Image/bubble.png");
    img[15]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //work by bubble
    surface=IMG_Load("Image/work by bubbles.png");
    img[16]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for hammer-nail
    surface=IMG_Load("Image/hammer&nail.png");
    img[19]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for ground
    surface=IMG_Load("Image/ground.png");
    img[20]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //nail
    surface=IMG_Load("Image/nail.png");
    img[21]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for hammer
    surface=IMG_Load("Image/hammer.png");
    img[22]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //wave
    surface=IMG_Load("Image/beats & melody.png");
    img[24]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //wave 1
    surface=IMG_Load("Image/wave1.png");
    img[25]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //wave1
    surface=IMG_Load("Image/wave2.png");
    img[26]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //wave 3
    surface=IMG_Load("Image/wave3.png");
    img[27]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //wave 4
    surface=IMG_Load("Image/wave4.png");
    img[28]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //tunic fork 1
    surface=IMG_Load("Image/tunic fork 1.png");
    img[29]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //tunic fork 2
    surface=IMG_Load("Image/tunic fork 2.png");
    img[30]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod center
    surface=IMG_Load("Image/1.rod center.png");
    img[32]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod end
    surface=IMG_Load("Image/1.rod end.png");
    img[33]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod c1
    surface=IMG_Load("Image/1.rod center 1.png");
    img[34]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod c2
    surface=IMG_Load("Image/1.rod center 2.png");
    img[35]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod c3
    surface=IMG_Load("Image/1.rod center 3.png");
    img[36]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod c4
    surface=IMG_Load("Image/1.rod center 4.png");
    img[37]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod e1
    surface=IMG_Load("Image/1.rod end 1.png");
    img[38]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod e2
    surface=IMG_Load("Image/1.rod end 2.png");
    img[39]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod e3
    surface=IMG_Load("Image/1.rod end 3.png");
    img[40]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod e4
    surface=IMG_Load("Image/1.rod end 4.png");
    img[41]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod e5
    surface=IMG_Load("Image/1.rod end 5.png");
    img[42]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //rod e6
    surface=IMG_Load("Image/1.rod end 6.png");
    img[43]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //triangle
    surface=IMG_Load("Image/2.triangle.png");
    img[45]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //triangle 1
    surface=IMG_Load("Image/2.triangle 1.png");
    img[46]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //triangle 2
    surface=IMG_Load("Image/2.triangle 2.png");
    img[47]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //triangle 3
    surface=IMG_Load("Image/2.triangle 3.png");
    img[48]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //triangle4
    surface=IMG_Load("Image/2.triangle 4.png");
    img[49]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc
    surface=IMG_Load("Image/3.disc center.png");
    img[51]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia
    surface=IMG_Load("Image/3.disc diameter.png");
    img[52]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc tan
    surface=IMG_Load("Image/3.disc tangent.png");
    img[53]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc center1
    surface=IMG_Load("Image/3.disc center 1.png");
    img[54]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc center2
    surface=IMG_Load("Image/3.disc center 2.png");
    img[55]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia
    surface=IMG_Load("Image/3.disc diameter 1.png");
    img[56]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia2
    surface=IMG_Load("Image/3.disc diameter 2.png");
    img[57]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia3
    surface=IMG_Load("Image/3.disc diameter 3.png");
    img[58]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia4
    surface=IMG_Load("Image/3.disc diameter 4.png");
    img[59]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia5
    surface=IMG_Load("Image/3.disc diameter 5.png");
    img[60]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia6
    surface=IMG_Load("Image/3.disc diameter 6.png");
    img[61]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia7
    surface=IMG_Load("Image/3.disc diameter 7.png");
    img[62]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc dia8
    surface=IMG_Load("Image/3.disc diameter 8.png");
    img[63]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc tan
    surface=IMG_Load("Image/3.disc tangent 1.png");
    img[64]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc tan2
    surface=IMG_Load("Image/3.disc tangent 2.png");
    img[65]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc tan3
    surface=IMG_Load("Image/3.disc tangent 3.png");
    img[66]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //disc tan4
    surface=IMG_Load("Image/3.disc tangent 4.png");
    img[67]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring cen
    surface=IMG_Load("Image/4.ring center.png");
    img[69]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring dia
    surface=IMG_Load("Image/4.ring diameter.png");
    img[70]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring tan
    surface=IMG_Load("Image/4.ring tangent.png");
    img[71]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an1
    surface=IMG_Load("Image/4.ring center 1.png");
    img[72]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an2
    surface=IMG_Load("Image/4.ring center 2.png");
    img[73]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an3
    surface=IMG_Load("Image/4.ring diameter 1.png");
    img[74]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an4
    surface=IMG_Load("Image/4.ring diameter 2.png");
    img[75]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an5
    surface=IMG_Load("Image/4.ring diameter 3.png");
    img[76]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an6
    surface=IMG_Load("Image/4.ring diameter 4.png");
    img[77]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an7
    surface=IMG_Load("Image/4.ring diameter 5.png");
    img[78]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an8
    surface=IMG_Load("Image/4.ring diameter 6.png");
    img[79]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring a9
    surface=IMG_Load("Image/4.ring diameter 7.png");
    img[80]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring an10
    surface=IMG_Load("Image/4.ring diameter 8.png");
    img[81]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring a11
    surface=IMG_Load("Image/4.ring tangent 1.png");
    img[82]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring a12
    surface=IMG_Load("Image/4.ring tangent 2.png");
    img[83]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring a13
    surface=IMG_Load("Image/4.ring tangent 3.png");
    img[84]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //ring a14
    surface=IMG_Load("Image/4.ring tangent 4.png");
    img[85]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere
    surface=IMG_Load("Image/5.sphere center.png");
    img[87]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere tan
    surface=IMG_Load("Image/5.sphere tangent.png");
    img[88]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere an
    surface=IMG_Load("Image/5.sphere center 1.png");
    img[89]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere an2
    surface=IMG_Load("Image/5.sphere center 2.png");
    img[90]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere an3
    surface=IMG_Load("Image/5.sphere tangent 1.png");
    img[91]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere an4
    surface=IMG_Load("Image/5.sphere tangent 2.png");
    img[92]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere an5
    surface=IMG_Load("Image/5.sphere tangent 3.png");
    img[93]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for sphere an6
    surface=IMG_Load("Image/5.sphere tangent 4.png");
    img[94]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //for pulley
    surface=IMG_Load("Image/pulley head.png");
    img[97]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[21]={555,384,81,43};
    SDL_FreeSurface(surface);
    //for Ball
    surface=IMG_Load("Image/sphere.png");
    img[6]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //background option
    surface=IMG_Load("Image/bg.png");
    img[7]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);

    //option button
    //for problem index
    surface=IMG_Load("Button-img/index.png");
    img[96]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[20]={450,40,360,80};
    SDL_FreeSurface(surface);
    //1.inclined plane
    surface=IMG_Load("Button-img/1 inclined planes.png");
    img[8]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[6]={70,180,290,80};
    SDL_FreeSurface(surface);
    //2.impulse
    surface=IMG_Load("Button-img/2 impulsive force.png");
    img[9]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[7]={70,300,290,80};//{128,125,250,55};
    SDL_FreeSurface(surface);
    //3.pulley
    surface=IMG_Load("Button-img/3 pulley.png");
    img[10]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[8]={70,420,290,80};//{128,160,250,55};
    SDL_FreeSurface(surface);
    //4.rotational motion
    surface=IMG_Load("Button-img/4 rotational motion.png");
    img[11]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[9]={70,540,290,80};
    SDL_FreeSurface(surface);
    //5.depth_measurement
    surface=IMG_Load("Button-img/5 depth measurement.png");
    img[13]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[10]={70,660,290,80};
    SDL_FreeSurface(surface);
    //6 wave melody
    surface=IMG_Load("Button-img/6 wave melody.png");
    img[17]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[11]={485,180,290,80};
    SDL_FreeSurface(surface);
    //7 angular momentum
    surface=IMG_Load("Button-img/7 angular momentum.png");
    img[18]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[12]={485,300,290,80};
    SDL_FreeSurface(surface);
    //8 surface tension
    surface=IMG_Load("Button-img/8 surface tension.png");
    img[23]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[13]={485,420,290,80};
    SDL_FreeSurface(surface);
    //9 hammer nail
    surface=IMG_Load("Button-img/9 hammer nail.png");
    img[31]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[14]={485,540,290,80};
    SDL_FreeSurface(surface);
    //10.rod
    surface=IMG_Load("Button-img/10.rod.png");
    img[44]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[15]={485,660,290,80};
    SDL_FreeSurface(surface);
    //11.triangle
    surface=IMG_Load("Button-img/11.triangle.png");
    img[50]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[16]={900,180,290,80};
    SDL_FreeSurface(surface);
    //12.disc
    surface=IMG_Load("Button-img/12.disc.png");
    img[68]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[17]={900,300,290,80};
    SDL_FreeSurface(surface);
    //13.ring
    surface=IMG_Load("Button-img/13.ring.png");
    img[86]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[18]={900,420,290,80};
    SDL_FreeSurface(surface);
    //14.sphere
    surface=IMG_Load("Button-img/14.sphere.png");
    img[95]=SDL_CreateTextureFromSurface(render,surface);
    img_rect[19]={900,540,290,80};
    SDL_FreeSurface(surface);
    //button 1
    surface=IMG_Load("Button-img/1 inclined planesB.png");
    img[98]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 2
    surface=IMG_Load("Button-img/2 impulsive forceB.png");
    img[99]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 3
    surface=IMG_Load("Button-img/3 pulleyB.png");
    img[100]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 4
    surface=IMG_Load("Button-img/4 rotational motionB.png");
    img[101]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 5
    surface=IMG_Load("Button-img/5 depth measurementB.png");
    img[102]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 6
    surface=IMG_Load("Button-img/6 wave melodyB.png");
    img[103]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 7
    surface=IMG_Load("Button-img/7 angular momentumB.png");
    img[104]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 8
    surface=IMG_Load("Button-img/8 surface tensionB.png");
    img[105]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 9
    surface=IMG_Load("Button-img/9 hammer nailB.png");
    img[106]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 10
    surface=IMG_Load("Button-img/10.rodB.png");
    img[107]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 11
    surface=IMG_Load("Button-img/11.triangleB.png");
    img[108]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 12
    surface=IMG_Load("Button-img/12.discB.png");
    img[109]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 13
    surface=IMG_Load("Button-img/13.ringB.png");
    img[110]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    //button 14
    surface=IMG_Load("Button-img/14.sphereB.png");
    img[111]=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
}
