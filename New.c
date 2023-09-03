#include "RayLib.h"
#include "stdio.h"

//For The text
int x = 0;
int y = 500/2;

int x2 = 375;
int y2 = 500;

int score = 0;
int score2 = 0;

//ball
int cx = 200;
int cy = 300;

void control(){
        if (IsKeyDown(265)){
            y-=10;
        }
        if (IsKeyDown(264)){
            y+=10;
        }
        if (IsKeyDown(87)){
            y2 -= 10;
        }
        if (IsKeyDown(83)){
            y2+=10;
        }
        if(y>500){
            y -= 10;
        }
        if(y<0){
            y += 10;
        }
        if(y2>500){
            y2 -= 10;
        }
        if(y2<0){
            y2 += 10;
        }
}

int main(){
    InitWindow(400,600,"Whacky PONG by Kanishk");
    SetTargetFPS(30);
    int Rx = GetRandomValue(-1,1);
    int Ry =  GetRandomValue(-1,1);
    Rectangle rt = {0,0,1,600};
    Rectangle rl = {399,0,1,600};
    
    Rectangle up = {0,0,400,1};
    Rectangle bl = {0,599,400,1};
   
    while(!WindowShouldClose()){
        Rectangle paddle1 = {x,y,30,100};
        Rectangle paddle2 = {x2,y2,30,100};
        
        Vector2 vec;
        vec.x = cx;
        vec.y = cy;
        
        int velocityx = 5;
        int velocityy = 5;
        
        if (CheckCollisionCircleRec(vec,60,paddle1)){
            Rx =-Rx;
            Ry =GetRandomValue(-1,1);
        }
        if (CheckCollisionCircleRec(vec,60,paddle2)){
            Rx =-Rx;
            Ry = GetRandomValue(-1,1);
        }
        if (CheckCollisionCircleRec(vec,60,rt)){
            score2++;
            cx = 200;
            cy = 300;
        }
        if (CheckCollisionCircleRec(vec,60,rl)){
            score++;
            cx = 200;
            cy = 300;
            
        }
        if (CheckCollisionCircleRec(vec,60,up)){
            Ry =-Ry;
            Rx =GetRandomValue(-1,1);
            if (Rx == 0){
                Rx = GetRandomValue(-1,1);
            }
        }
        if (CheckCollisionCircleRec(vec,60,bl)){
            Ry =-Ry;
            Rx = GetRandomValue(-1,1);
            if (Rx == 0){
                Rx = GetRandomValue(-1,1);
            }
        }

        cx+= velocityx*Rx;
        cy+= velocityy*Ry;
        control();
        BeginDrawing();
        SwapScreenBuffer();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(paddle1,BLACK);
        DrawRectangleRec(rt,BLACK);
        DrawRectangleRec(rl,BLACK);
        DrawRectangleRec(up,BLACK);
        DrawRectangleRec(bl,BLACK);
        DrawLine(400/2,0,400/2,600,BLACK);
        DrawText(TextFormat("%d ",score),175,0,32,BLACK);
        DrawText(TextFormat(" %d",score2),210,0,32,BLACK);
        DrawCircle(cx,cy,20,BLACK);
        DrawRectangleRec(paddle2,BLACK);

        
        EndDrawing();
    }
}