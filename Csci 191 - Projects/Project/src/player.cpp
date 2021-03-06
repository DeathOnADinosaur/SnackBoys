#include <player.h>
#include <timer.h>
#include <GLTexture.h>
#include <windows.h>
#include <iostream>
//#include<gameclasses.h>
timer *T = new timer();
timer *T2 = new timer();
char lastCase;

textureLoader runText[40];
textureLoader runText_left[40];
textureLoader swingText[40];
textureLoader swingTextLeft[40];
textureLoader stand[2];
player::player()
{
    //ctor
    //PRotateX =0.0; // Rotations
    //PRotateY =0.0;
    //PRotateZ =0.0;

    PZoom = -4;  //translations
    PXpos = 0;
    PYpos = -1.5;

        verticies[0].x=-0.5;verticies[0].y=-0.5;verticies[0].z=-1.0;
        verticies[1].x=0.5;verticies[1].y=-0.5;verticies[1].z=-1.0;
        verticies[2].x=0.5;verticies[2].y=0.5;verticies[2].z=-1.0;
        verticies[3].x=-0.5;verticies[3].y=0.5;verticies[3].z=-1.0;
    runspeed  = 0;
    jumpspeed = 0;
    actionTrigger = 0;
    this->playerHBox.width = 0;
}
player::~player()
{
    //dtor
}
void player::drawplayer()
{
  //  glColor3f(1.0,0.0,0.0);
    //glPushMatrix();
    glTranslated(PXpos,PYpos,PZoom);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0);
    glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);
    glTexCoord2f(1.0,1.0);
    glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);
    glTexCoord2f(1.0,0.0);
    glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);
    glTexCoord2f(0.0,0.0);
    glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);
    glEnd();
    //glPopMatrix();
}
void player::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T2->start();
    T->start();
    runText[0].bindTexture("images/player_right/player0.png");
    runText[1].bindTexture("images/player_right/player1.png");
    runText[2].bindTexture("images/player_right/player2.png");
    runText[3].bindTexture("images/player_right/player3.png");
    runText[4].bindTexture("images/player_right/player4.png");
    runText[5].bindTexture("images/player_right/player5.png");



    runText_left[0].bindTexture("images/player_left/player0.png");
    runText_left[1].bindTexture("images/player_left/player1.png");
    runText_left[2].bindTexture("images/player_left/player2.png");
    runText_left[3].bindTexture("images/player_left/player3.png");
    runText_left[4].bindTexture("images/player_left/player4.png");
    runText_left[5].bindTexture("images/player_left/player5.png");


    swingText[0].bindTexture("images/player/swing1.png");
    swingText[1].bindTexture("images/player/swing2.png");
    swingText[2].bindTexture("images/player/swing3.png");
    swingText[3].bindTexture("images/player/swing3.png");
    swingText[4].bindTexture("images/player/swing3.png");
    swingText[5].bindTexture("images/player/swing3.png");
    swingText[6].bindTexture("images/player/swing3.png");
    swingText[7].bindTexture("images/player/swing3.png");
    swingText[8].bindTexture("images/player/swing3.png");
    swingText[9].bindTexture("images/player/swing3.png");
    swingText[10].bindTexture("images/player/swing3.png");
    swingText[11].bindTexture("images/player/swing3.png");
    swingText[12].bindTexture("images/player/swing3.png");

    swingTextLeft[0].bindTexture("images/player_left/swing1.png");
    swingTextLeft[1].bindTexture("images/player_left/swing2.png");
    swingTextLeft[2].bindTexture("images/player_left/swing3.png");
    swingTextLeft[3].bindTexture("images/player_left/swing3.png");
    swingTextLeft[4].bindTexture("images/player_left/swing3.png");
    swingTextLeft[5].bindTexture("images/player_left/swing3.png");
    swingTextLeft[6].bindTexture("images/player_left/swing3.png");
    swingTextLeft[7].bindTexture("images/player_left/swing3.png");
    swingTextLeft[8].bindTexture("images/player_left/swing3.png");
    swingTextLeft[9].bindTexture("images/player_left/swing3.png");
    swingTextLeft[10].bindTexture("images/player_left/swing3.png");
    swingTextLeft[11].bindTexture("images/player_left/swing3.png");
    swingTextLeft[12].bindTexture("images/player_left/swing3.png");


   stand[0].bindTexture("images/player_right/play.png");

   stand[1].bindTexture("images/player_left/play.png");

}
void player::actions(int action, player* ply, Model* mdl)
{
   switch(action){
       case 0:
       glPushMatrix();
           glTranslated(PXpos,PYpos,PZoom);
           stand[0].binder();

           drawplayer();
       glPopMatrix();
       lastCase = 'R';
              break;
   case 1:
       glPushMatrix();
            glTranslated(PXpos,PYpos,PZoom);
            if(T->getTicks()>.25)
            {


                if (PXpos <= 3.4) // 3.1 = edgde
                {

                PXpos += 0.005;
                mdl->Xpos += 0.005;
                T->reset();
                }
            }

            if(T2 ->getTicks()>80)
            {
                runspeed++;
                runspeed = (runspeed % 5);
                T2->reset();
            }

            runText[runspeed].binder();


            drawplayer();
       glPopMatrix();
       lastCase = 'R';
    break;

   case 2:
       glPushMatrix();
           glTranslated(PXpos,PYpos,PZoom);
           if(T->getTicks()>.25)
           {
               if (PXpos >= -3.4) //
                {
                PXpos -= 0.005;
                mdl->Xpos -= 0.005;
                T->reset();
                }
           }
          if(T2 ->getTicks()>80)
          {
            runspeed++;
            runspeed = (runspeed % 5);
            T2->reset();
          }

           runText_left[runspeed].binder();
           drawplayer();
       glPopMatrix();
       lastCase = 'L';
    break;

    case 3:
       glPushMatrix();
           glTranslated(PXpos,PYpos,PZoom);
            stand[1].binder();
           drawplayer();
       glPopMatrix();
              break;


    case 4:
        if (lastCase == 'R')
        {
           glPushMatrix();
              if(T2 ->getTicks()>80)
              {
                runspeed++;
                runspeed = (runspeed % 8);
                T2->reset();
              }

               swingText[runspeed].binder();
               drawplayer();
           glPopMatrix();
        }
        if (lastCase == 'L')
        {
           glPushMatrix();
              if(T2 ->getTicks()>80)
              {
                runspeed++;
                runspeed = (runspeed % 8);
                T2->reset();
              }

               swingTextLeft[runspeed].binder();
               drawplayer();
           glPopMatrix();
        }
    break;
   }


}
 void player::playerUpdateHbox()//updates the hitbox location to the players location
 {

    this->playerHBox.x= this->PXpos;
    this->playerHBox.y= this->PYpos;

      return;
 }
