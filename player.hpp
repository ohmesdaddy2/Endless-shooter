/* 
 * File:   player.hpp
 * Author: garys
 *
 * Created on October 26, 2013, 1:46 PM
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "guntypes.hpp"
#include "bullets.hpp"
#include "Weapon.hpp"

class character{
    short x, y, w ,h;
    weapon gun;
public:
    
    character(){
        gun.set_type(man_Pistol);
    }
    short getx(){
        return x;
    }
    void place(short a, short b){
        x = a;
        y = b;
        w = 30;
        h = 30;
    }
    void move_left(){
        if (x > 0){
            x = x - 2;
            //w = w - 2;
        }
    }
    void move_right(SDL_Surface* screen){
        if (w < screen-> w){
            x = x + 2;
            //w = w + 2;
        }
    }
    void upgrade_gun(Uint32 type){
        gun.set_type(type);
    }
    void fire(engine::pointer z){
        gun.set_target(z);
    }
    void render(SDL_Surface* screen){
        boxRGBA(screen, x, y, x + w, y + h, 0, 255, 128, 255);
    }
};

#endif	/* PLAYER_HPP */

