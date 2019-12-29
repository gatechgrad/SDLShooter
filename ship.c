//2019 Levi D. Smith - levidsmith.com
#include "globals.h"
#include <stdlib.h>

#include "linked_list.h"
#include "ship.h"
#include "bullet.h"

#define NUM_WEAPONS 5

extern SDL_Renderer *renderer;
extern SDL_Texture *imgShip;
extern Mix_Chunk *soundShoot;
extern Mix_Chunk *soundWeaponSelect;



void init_ship(struct Ship *ship) {
  ship->width = 64;
  ship->height = 64;
  ship->vel_x = 0;
  ship->vel_y = 0;
  ship->x = (SCREEN_WIDTH - ship->width) / 2;
  ship->y = 720 - 128;
  ship->isAlive = TRUE;
  ship->fShootDelay = 0;
  ship->fMaxShootDelay = 0.5;
  ship->fMaxEnergy = 200;
  ship->fEnergy = ship->fMaxEnergy;
  ship->iWeaponType = 0;

}


void update_ship(struct Ship *ship) {
	  //update ship
  if (ship->isAlive) {
    ship->x += ship->vel_x * DELTA_TIME;
    ship->y += ship->vel_y * DELTA_TIME;

    if (ship->x < ship->width) {
      ship->x = ship->width;
    }

    if (ship->y < ship->height) {
      ship->y = ship->height;
    }

    if (ship->x > SCREEN_WIDTH - (ship->width * 2)) {
      ship->x = SCREEN_WIDTH - (ship->width * 2);
    }

    if (ship->y > SCREEN_HEIGHT - (ship->height * 2)) {
      ship->y = SCREEN_HEIGHT - (ship->height * 2);
    }
  }
  
  if (ship->fShootDelay > 0) {
	  ship->fShootDelay -= DELTA_TIME;
	  if (ship->fShootDelay < 0) {
		  ship->fShootDelay = 0;
	  }
  }
  
  //update energy
  ship->fEnergy += 10 * DELTA_TIME;
  if (ship->fEnergy > ship->fMaxEnergy) {
	  ship->fEnergy = ship->fMaxEnergy;
  }
	
}

void draw_ship(struct Ship *ship) {
	SDL_Rect pos;
  //Draw the ship
  if (ship->isAlive) {
	pos.x = ship->x;
	pos.y = ship->y;
	pos.w = ship->width;
	pos.h = ship->height;
    SDL_RenderCopy(renderer, imgShip, NULL, &pos);
  }

	
}

void shoot_ship(struct Ship *ship, int iLevel, struct Node **listBullet) {
//	ship->fShootDelay = 0.5;
    int iEnergyRequired = 5;

  if (ship->iWeaponType == 0) {

      iEnergyRequired = 5;
	if (ship->fEnergy >= iEnergyRequired) {
		struct Bullet *bullet;
		
		bullet = malloc(sizeof(struct Bullet));
		init_bullet(bullet, ship->x + ship->width / 2, ship->y);
		bullet->vel_y = -5;
		bullet->iHitsEnemy = TRUE;


		
		ship->fShootDelay = ship->fMaxShootDelay;
		ship->fEnergy -= iEnergyRequired;
		
		add_node(listBullet, bullet);

		
		Mix_PlayChannel(-1, soundShoot, 0);
	}
  } else if (ship->iWeaponType == 1) {
      float fShootDelay = 0.5;
      switch(iLevel) {
          case 0:
              iEnergyRequired = 8;
              fShootDelay = 0.4;
              break;
          case 1:
              iEnergyRequired = 12;
              fShootDelay = 0.2;
              break;
          case 2:
              iEnergyRequired = 16;
              fShootDelay = 0.1;
              break;
              
      }

	if (ship->fEnergy >= iEnergyRequired) {
		struct Bullet *bullet;
		
		bullet = malloc(sizeof(struct Bullet));
		init_bullet(bullet, ship->x + ship->width / 2, ship->y);
		bullet->vel_y = -5;
		bullet->iHitsEnemy = TRUE;


		
		ship->fShootDelay = fShootDelay;
		ship->fEnergy -= iEnergyRequired;
		
		add_node(listBullet, bullet);

		
		Mix_PlayChannel(-1, soundShoot, 0);
	}
	
	
  } else if (ship->iWeaponType == 2) {
      switch(iLevel) {
          case 0:
              iEnergyRequired = 10;
              break;
          case 1:
              iEnergyRequired = 20;
              break;
          case 2:
              iEnergyRequired = 30;
              break;
      }
      
      
	if (ship->fEnergy >= iEnergyRequired) {
		struct Bullet *bullet;
        float fVelX;
        float fVelY;
        
        if (iLevel == 0) {
            fVelX = 0.5; //sin(30)
            fVelY = 0.8660; //cos(30)

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_x = 5.0 * fVelX;
            bullet->vel_y = -5.0 * fVelY;
            bullet->iHitsEnemy = TRUE;
            add_node(listBullet, bullet);

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_x = -5.0 * fVelX;
            bullet->vel_y = -5.0 * fVelY;
            bullet->iHitsEnemy = TRUE;
            add_node(listBullet, bullet);

            
        } else if (iLevel == 1) {
            fVelX = 0.7071; //sin(45)
            fVelY = 0.7071; //cos(45)
		
		bullet = malloc(sizeof(struct Bullet));
		init_bullet(bullet, ship->x + ship->width / 2, ship->y);
		bullet->vel_y = -5;
		bullet->iHitsEnemy = TRUE;
		add_node(listBullet, bullet);

		bullet = malloc(sizeof(struct Bullet));
		init_bullet(bullet, ship->x + ship->width / 2, ship->y);
		bullet->vel_x = 5.0 * fVelX;
		bullet->vel_y = -5.0 * fVelY;
		bullet->iHitsEnemy = TRUE;
		add_node(listBullet, bullet);

		bullet = malloc(sizeof(struct Bullet));
		init_bullet(bullet, ship->x + ship->width / 2, ship->y);
		bullet->vel_x = 5.0 * -fVelX;
		bullet->vel_y = -5.0 * fVelY;
		bullet->iHitsEnemy = TRUE;
		add_node(listBullet, bullet);
        } else if (iLevel == 2) {
            
            fVelX = 0.2588; //sin(15)
            fVelY = 0.9659; //cos(15)

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_x = 5.0 * fVelX;
            bullet->vel_y = -5.0 * fVelY;
            bullet->iHitsEnemy = TRUE;
            add_node(listBullet, bullet);

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_x = -5.0 * fVelX;
            bullet->vel_y = -5.0 * fVelY;
            bullet->iHitsEnemy = TRUE;
            add_node(listBullet, bullet);

            fVelX = 0.7071; //sin(45)
            fVelY = 0.7071; //cos(45)

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_x = 5.0 * fVelX;
            bullet->vel_y = -5.0 * fVelY;
            bullet->iHitsEnemy = TRUE;
            add_node(listBullet, bullet);

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_x = -5.0 * fVelX;
            bullet->vel_y = -5.0 * fVelY;
            bullet->iHitsEnemy = TRUE;
            add_node(listBullet, bullet);

        }

		
		ship->fShootDelay = ship->fMaxShootDelay;
		ship->fEnergy -= iEnergyRequired;
		

		
		Mix_PlayChannel(-1, soundShoot, 0);
	}
  } else if (ship->iWeaponType == 3) {
      switch (iLevel) {
          case 0:
              iEnergyRequired = 7;
              break;
          case 1:
              iEnergyRequired = 14;
              break;
          case 2:
              iEnergyRequired = 28;
              break;
      }
      
	if (ship->fEnergy >= iEnergyRequired) {
		struct Bullet *bullet;
		
        if (iLevel == 0) {
            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = 2;
            add_node(listBullet, bullet);

        } else if (iLevel == 1) {
            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = 2;
            add_node(listBullet, bullet);


            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = -2;
            add_node(listBullet, bullet);
            
        } else if (iLevel == 2) {
            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = 2;
            add_node(listBullet, bullet);

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = -2;
            add_node(listBullet, bullet);

            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = 4;
            add_node(listBullet, bullet);


            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fWaveAmplitude = -4;
            add_node(listBullet, bullet);
        }

		
		ship->fShootDelay = ship->fMaxShootDelay;
		ship->fEnergy -= iEnergyRequired;
		

		
		Mix_PlayChannel(-1, soundShoot, 0);
	}
		
  } else if (ship->iWeaponType == 4) {
      switch(iLevel) {
          case 0:
              iEnergyRequired = 12;
              break;
          case 1:
              iEnergyRequired = 24;
              break;
          case 2:
              iEnergyRequired = 48;
              break;
      }
      
	if (ship->fEnergy >= iEnergyRequired) {
		struct Bullet *bullet;
		
        if (iLevel == 0) {
            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fBlastRadius = 2;
            add_node(listBullet, bullet);
        } else if (iLevel == 1) {
            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fBlastRadius = 3;
            add_node(listBullet, bullet);

        } else if (iLevel == 2) {
            bullet = malloc(sizeof(struct Bullet));
            init_bullet(bullet, ship->x + ship->width / 2, ship->y);
            bullet->vel_y = -5;
            bullet->iHitsEnemy = TRUE;
            bullet->fBlastRadius = 4;
            add_node(listBullet, bullet);

        }


		ship->fShootDelay = ship->fMaxShootDelay;
		ship->fEnergy -= iEnergyRequired;
		

		
		Mix_PlayChannel(-1, soundShoot, 0);
	}
	  
  }
}

void increaseFireRate_ship(struct Ship *ship) {
    //changed powerup to give energy instead of increasing shot rate
	ship->fEnergy += 50;
	if (ship->fEnergy > ship->fMaxEnergy) {
		ship->fEnergy = ship->fMaxEnergy;
	}
	
}

void selectWeaponUp_ship(struct Ship *ship) {
	ship->iWeaponType++;
	if (ship->iWeaponType >= NUM_WEAPONS) {
		ship->iWeaponType = 0;
	}
	Mix_PlayChannel(-1, soundWeaponSelect, 0);

}

float getCenterX_ship(struct Ship *ship) {
	return ship->x + (ship->width / 2);
}

float getCenterY_ship(struct Ship *ship) {
	return ship->y + (ship->height / 2);
}
