//2019 Levi D. Smith - levidsmith.com

#ifndef bullet_h
#define bullet_h

struct Bullet {
  float x;
  float y;
  float vel_y;
  float vel_x;
  float orig_x;
  float orig_y;
  int width;
  int height;
  int isAlive;
  int iHitsPlayer;
  int iHitsEnemy;
  float fWaveAmplitude;
  float fLifetime;
  float fBlastRadius;
    int isSpinShot;
	int iWeaponType;
	int iDamage;
	int iLevel;
	float fSeekRadius;
	struct Enemy *seekEnemy;
  int iDamageMultiplier;
};

void init_bullet(struct Bullet *, int, int, int);
void update_bullet(struct Bullet *);
void draw_bullet(struct Bullet *);
float getCenterX_bullet(struct Bullet *bullet);
float getCenterY_bullet(struct Bullet *bullet);
void seekEnemy_bullet(struct Bullet *bullet);

#endif