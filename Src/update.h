//user defined header
#include "Option.h"
#include "image_ren.h"
#include "problem_Rotational_Motion.h"
#include "problem_Depth_Measurement.h"
#include "problem_Surface_Tension.h"
#include "problem_Hammer_Nail.h"
#include "problem_Wave_Melody.h"
#include "problem_Angular_Momentum.h"
#include "problem_Inertia_1_Rod.h"
#include "problem_Inertia_2_Triangle.h"
#include "problem_Inertia_3_Disc.h"
#include "problem_Inertia_4_Ring.h"
#include "problem_Inertia_5_Sphere.h"

const int SCREEN_HEIGHT= 850;
const int SCREEN_WIDTH= 1260;
SDL_Window* window=NULL;
SDL_Surface* surface=NULL;
SDL_Renderer* render=NULL;
SDL_Texture* tex=NULL;

extern SDL_Texture* img[120];
extern SDL_Rect img_rect[50];

void special_effect(SDL_Rect rect[]);
void finish();

bool init(){
    bool success=true;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("Couldn't Initialize %s\n",SDL_GetError());
        success= false;
    }
    else{
       window= SDL_CreateWindow("Mechanical Calculator",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
       if(window==NULL){
           printf("NO Window %s\n",SDL_GetError());
           success=false;
       }
    }
    return success;
}

void update(){
    bool run=true;
    SDL_Event ev;
    render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    surface= IMG_Load("Image/img.png");
    if(!surface){
        printf("Couldn't load image %s\n",SDL_GetError());
    }
    tex=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    if(!tex){
        printf("NO Texture %s\n",SDL_GetError());
    }
    SDL_RenderClear(render);
    SDL_RenderCopy(render,tex,NULL,NULL);
    SDL_RenderPresent(render);
    SDL_Delay(3000);
    surface=IMG_Load("Image/screen.png");
    tex=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    Load_image(render);
    int mouse_x,mouse_y;
    while(run){
        SDL_RenderClear(render);
        SDL_RenderCopy(render,tex,NULL,NULL);
        while(SDL_PollEvent(&ev)){
            switch(ev.type){
                case SDL_MOUSEMOTION:
                    mouse_x=ev.motion.x;
                    mouse_y=ev.motion.y;
                    break;
                case SDL_QUIT:
                    run=0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                    if((mouse_x>70&&mouse_x<360)&&(mouse_y>180&&mouse_y<260)){
                        OptionINCP(window,render,img,img_rect,mouse_x,mouse_y);
                    }
                    else if((mouse_x>70&&mouse_x<360)&&(mouse_y>300&&mouse_y<380))
                    OptionImpulse(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>70&&mouse_x<360)&&(mouse_y>420&&mouse_y<500))
                    OptionAtwood(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>70&&mouse_x<360)&&(mouse_y>540&&mouse_y<620))
                    ROTATIONAL_MOTION(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>70&&mouse_x<360)&&(mouse_y>660&&mouse_y<740))
                    Depth_Measurement(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>485&&mouse_x<775)&&(mouse_y>180&&mouse_y<260))
                    Wave_Melody(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>485&&mouse_x<775)&&(mouse_y>300&&mouse_y<380))
                    Angular_Momentum(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>485&&mouse_x<775)&&(mouse_y>420&&mouse_y<500))
                    Surface_Tension(window,render,img,img_rect,mouse_x,mouse_y);
                    else if ((mouse_x>485&&mouse_x<775)&&(mouse_y>540&&mouse_y<620))
                    Hammer_Nail(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>485&&mouse_x<775)&&(mouse_y>660&&mouse_y<740))
                    Inertia_1_Rod(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>900&&mouse_x<1190)&&(mouse_y>180&&mouse_y<260))
                    Inertia_2_Triangle(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>900&&mouse_x<1190)&&(mouse_y>300&&mouse_y<380))
                    Inertia_3_Disc(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>900&&mouse_x<1190)&&(mouse_y>420&&mouse_y<500))
                    Inertia_4_Ring(window,render,img,img_rect,mouse_x,mouse_y);
                    else if((mouse_x>900&&mouse_x<1190)&&(mouse_y>540&&mouse_y<620))
                    Inertia_5_Sphere(window,render,img,img_rect,mouse_x,mouse_y);
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
        //for image option
        SDL_RenderCopy(render,img[96],NULL,&img_rect[20]);
        if((mouse_x>70&&mouse_x<360)&&(mouse_y>180&&mouse_y<260))
            SDL_RenderCopy(render,img[98],NULL,&img_rect[6]);
        else SDL_RenderCopy(render,img[8],NULL,&img_rect[6]);
        if((mouse_x>70&&mouse_x<360)&&(mouse_y>300&&mouse_y<380))
            SDL_RenderCopy(render,img[99],NULL,&img_rect[7]);
        else SDL_RenderCopy(render,img[9],NULL,&img_rect[7]);
        if ((mouse_x>70&&mouse_x<360)&&(mouse_y>420&&mouse_y<500))
            SDL_RenderCopy(render,img[100],NULL,&img_rect[8]);
        else SDL_RenderCopy(render,img[10],NULL,&img_rect[8]);
        if ((mouse_x>70&&mouse_x<360)&&(mouse_y>540&&mouse_y<620))
            SDL_RenderCopy(render,img[101],NULL,&img_rect[9]);
        else SDL_RenderCopy(render,img[11],NULL,&img_rect[9]);
        if ((mouse_x>70&&mouse_x<360)&&(mouse_y>660&&mouse_y<740))
            SDL_RenderCopy(render,img[102],NULL,&img_rect[10]);
        else SDL_RenderCopy(render,img[13],NULL,&img_rect[10]);
        if ((mouse_x>485&&mouse_x<775)&&(mouse_y>180&&mouse_y<260))
            SDL_RenderCopy(render,img[103],NULL,&img_rect[11]);
        else SDL_RenderCopy(render,img[17],NULL,&img_rect[11]);
        if ((mouse_x>485&&mouse_x<775)&&(mouse_y>300&&mouse_y<380))
            SDL_RenderCopy(render,img[104],NULL,&img_rect[12]);
        else SDL_RenderCopy(render,img[18],NULL,&img_rect[12]);
        if ((mouse_x>485&&mouse_x<775)&&(mouse_y>420&&mouse_y<500))
            SDL_RenderCopy(render,img[105],NULL,&img_rect[13]);
        else SDL_RenderCopy(render,img[23],NULL,&img_rect[13]);
        if ((mouse_x>485&&mouse_x<775)&&(mouse_y>540&&mouse_y<620))
            SDL_RenderCopy(render,img[106],NULL,&img_rect[14]);
        else SDL_RenderCopy(render,img[31],NULL,&img_rect[14]);
        if((mouse_x>485&&mouse_x<775)&&(mouse_y>660&&mouse_y<740))
            SDL_RenderCopy(render,img[107],NULL,&img_rect[15]);
        else SDL_RenderCopy(render,img[44],NULL,&img_rect[15]);
        if((mouse_x>900&&mouse_x<1190)&&(mouse_y>180&&mouse_y<260))
            SDL_RenderCopy(render,img[108],NULL,&img_rect[16]);
        else SDL_RenderCopy(render,img[50],NULL,&img_rect[16]);
        if((mouse_x>900&&mouse_x<1190)&&(mouse_y>300&&mouse_y<380))
            SDL_RenderCopy(render,img[109],NULL,&img_rect[17]);
        else SDL_RenderCopy(render,img[68],NULL,&img_rect[17]);
        if((mouse_x>900&&mouse_x<1190)&&(mouse_y>420&&mouse_y<500))
            SDL_RenderCopy(render,img[110],NULL,&img_rect[18]);
        else SDL_RenderCopy(render,img[86],NULL,&img_rect[18]);
        if((mouse_x>900&&mouse_x<1190)&&(mouse_y>540&&mouse_y<620))
            SDL_RenderCopy(render,img[111],NULL,&img_rect[19]);
        else SDL_RenderCopy(render,img[95],NULL,&img_rect[19]);
        SDL_RenderPresent(render);
    }
    finish();
}

void finish(){
    SDL_DestroyTexture(tex);
    tex=NULL;
    for(int i=0;i<50;i++){
        SDL_DestroyTexture(img[i]);
        img[i]=NULL;
    }
    SDL_DestroyRenderer(render);
    render=NULL;
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_Quit();
}

