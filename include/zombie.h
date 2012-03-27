#ifndef ZOMBIE_H
#define ZOMBIE_H

#define ZOMBIE_SPEED 180 /* Walking speed of zombies in pixels per second. */

#define ZOMBIE(i)    game->zombie[i]			 /* Current zombie. */
#define ZOMBIE_X(i) (game->zombie[i].rect.x / TILE_SIZE) /* Current zombie position in     */
#define ZOMBIE_Y(i) (game->zombie[i].rect.y / TILE_SIZE) /* relation to the 'level' array. */

#define ZOMBIE_NODE(i) ZOMBIE(i).path[ZOMBIE(i).num_nodes] /* Current occupied node. */

/* Used in 'zombie_path_search()', this defines how long we will search for the destination.
 * Larger numbers mean more chances of success, but also more time spent searching. */
#define SEARCH_DEPTH 64

/* Used for storing the path generated by 'zombie_path_search()'. */
struct list {
	int x, y;		/* The node's location on the X / Y axis. */
	int f, g, h;		/* Information about the node, as per the A* algoarithm. */
	bool dropped;		/* Have we already walked this node? */
	struct list *parent; /* The parent node for each node. */
};

/* 
 * Calculate path for 'zombie' looking for walls and other obstructions along the way
 * in 'level'. Copies the path in the 'path' structure belonging to 'zombie' and
 * returns the number of nodes. An implementation of the A* pathfinding algoarithm.
 */
int zombie_path_search(struct npc *zombie, char level[LEVEL_H][LEVEL_W]);

/* 
 * Move zombies through level, chasing the player if found inside a radius of
 * 5 squares around the zombie.
 */
void zombie_move(struct game_data *game);

#endif
