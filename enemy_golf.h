struct EnemyGolf {
	struct Enemy *previous;
	struct Enemy *next;
	int iIsHead;
	int iFoo;
	float x_min;
	float x_max;
	float y_min;
	float y_max;


};

void init_enemy_golf(struct Enemy *enemy);
void update_enemy_golf(struct Enemy *enemy);
void draw_enemy_golf(struct Enemy *enemy);
//void init_enemy_golf_tail(struct Enemy *enemy, struct Enemy *previous);
void damage_enemy_golf(struct Enemy *enemy, int iDamageAmount);
int getIsTailDead(struct Enemy *enemy);
void updateMinMaxValues(struct Enemy *enemy);
void moveAll(struct Enemy *enemy, float x_move, float y_move);
int getCanFreeze_enemy_golf(struct Enemy *enemy);

