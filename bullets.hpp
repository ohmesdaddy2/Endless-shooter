/* 
 * File:   bullets.hpp
 * Author: garys
 *
 * Created on October 24, 2013, 11:45 AM
 */

#ifndef BULLETS_HPP
#define	BULLETS_HPP

#include "gameengine.h"

class bullet{
    short xSpeed, ySpeed;
public:
    short x, y, w;
    short endx, endy;
    bool fired;

    bullet(){
        xSpeed = 0;
        ySpeed = 0;
        
        fired = false;
        w = 10;
    }
    void reset(){
        fired = false;
    }
    
    void set_size(short a){
        w = a;
    }
    
    void set_angle(short a, short b){
        endx = a;
        endy = b;
        ySpeed = endy - y;
        xSpeed = (endx - x)/ySpeed;
        if (endx < x ){
            xSpeed = -xSpeed;
        }
        fired = true;
    }
    
    void fly(){
        y = y - ySpeed;
        x = x - xSpeed;
    }
    void place(short a, short b){
        x = a;
        y = b;
    }
    
    void render(SDL_Surface* screen){
        filledCircleRGBA(screen, x, y, w, 255, 255, 0, 255);
    }
};


#endif	/* BULLETS_HPP */

