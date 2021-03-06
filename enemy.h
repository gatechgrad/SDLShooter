//2019 Levi D. Smith - levidsmith.com

#ifndef enemy_h
#define enemy_h


struct Enemy {
  int iLevel;
  int iHealth;
  float x;
  float y;
  float orig_x;
  float orig_y;
  float target_x;
  float target_y;
  int iMoveToTarget;
  int width;
  int height;
  float vel_x;
  float vel_y;
  float fLifetime;
  float fActiveTime;
  float fChangeMovementCountdown;
  int isAlive;
  int iType;
  float fShootDelay;
  int hasDrop;
  float fDamagedCountdown;
  float fWaitCountdown;
  int iPoints;
  float fIntroDelay;
  float fFreezeDelay;
  float fMaxFreezeDelay;
  float fDeathDelay;
  float fMaxDeathDelay;
    int isRoot;
  void *subtype;
};

enum enemy_id { id_alpha, id_bravo, id_charlie, id_delta, id_echo, id_foxtrot, id_golf, id_hotel, id_india, id_juliett, id_kilo, id_lima, id_mike };




void init_enemy(struct Enemy *, int, int, int, int, int);
void update_enemy(struct Enemy *);
void draw_enemy(struct Enemy *);
void shoot_enemy(struct Enemy *enemy);
void setShootDelay_enemy(struct Enemy *);
void setTargetPosition_enemy(struct Enemy *enemy, float x, float y);
void damage_enemy(struct Enemy *enemy, int iDamageAmount);
void kill_enemy(struct Enemy *enemy);
void destroy_enemy(struct Enemy *enemy);
void updateActive_enemy(struct Enemy *enemy);
void updatePosition_enemy(struct Enemy *enemy, int iType, int iLevel);
void freeze_enemy(struct Enemy *enemy, int iFreezeLevel, int iDamageAmount);
float getCenterX_enemy(struct Enemy *enemy);
float getCenterY_enemy(struct Enemy *enemy);
void configure_enemy(struct Enemy *enemy);
int canDestroy_enemy(struct Enemy *enemy);
void draw_explosion_enemy(struct Enemy *enemy, SDL_Texture *img);

#endif
