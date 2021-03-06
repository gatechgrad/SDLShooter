//2019 Levi D. Smith

#ifndef screen_game_h
#define screen_game_h



void start_screen_game();
void update_screen_game();
void draw_screen_game();
void handleInput_screen_game(int iType, int iKey);

void shoot();
void updateDisplayText();
void checkCollisions();
void checkLevelComplete();
void updateTimeText();
void getWeaponColor(int iWeaponType, SDL_Color *c);
int collidedRectRect(float r1_x, float r1_y, float r1_w, float r1_h, float r2_x, float r2_y, float r2_w, float r2_h);
int collidedCircleRect(float c1_x, float c1_y, float c1_r, float r1_x, float r1_y, float r1_w, float r1_h);
void updateBackgroundPattern(int iRows);
void loadWorld();
void generateTextTexture(SDL_Texture **imgText, char *strText, SDL_Color colorText, TTF_Font *font);
void formatTime(char *strTime, Uint32 timeValue);

#endif
