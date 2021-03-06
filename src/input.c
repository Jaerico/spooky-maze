#include <stdio.h>
#include <SDL.h>

#include "game.h"
#include "input.h"
#include "player.h"

void input_handle(struct game_data *game)
{
	SDL_Event event;
	Uint8 *key = SDL_GetKeyState(NULL);

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				game->player.dir_y = 0;
				game->player.dir_y -= PLAYER_SPEED;
				break;
			case SDLK_DOWN:
				game->player.dir_y = 0;
				game->player.dir_y += PLAYER_SPEED;
				break;
			case SDLK_LEFT:
				game->player.dir_x = 0;
				game->player.dir_x -= PLAYER_SPEED;
				break;
			case SDLK_RIGHT:
				game->player.dir_x = 0;
				game->player.dir_x += PLAYER_SPEED;
				break;
			case SDLK_F11:
				SDL_WM_ToggleFullScreen(game->screen);
				break;
			case SDLK_ESCAPE:
				game_terminate(0);
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				game->player.dir_y = 0;
				if (key[SDLK_DOWN])
					game->player.dir_y += PLAYER_SPEED;
				break;
			case SDLK_DOWN:
				game->player.dir_y = 0;
				if (key[SDLK_UP])
					game->player.dir_y -= PLAYER_SPEED;
				break;
			case SDLK_LEFT:
				game->player.dir_x = 0;
				if (key[SDLK_RIGHT])
					game->player.dir_x += PLAYER_SPEED;
				break;
			case SDLK_RIGHT:
				game->player.dir_x = 0;
				if (key[SDLK_LEFT])
					game->player.dir_x -= PLAYER_SPEED;
				break;
			}
		break;
		case SDL_JOYBUTTONDOWN:
			switch (event.jbutton.button) {
			case JOYSTICK_UP:
				game->player.dir_y = 0;
				game->player.dir_y -= PLAYER_SPEED;
				break;
			case JOYSTICK_DOWN:
				game->player.dir_y = 0;
				game->player.dir_y += PLAYER_SPEED;
				break;
			case JOYSTICK_LEFT:
				game->player.dir_x = 0;
				game->player.dir_x -= PLAYER_SPEED;
				break;
			case JOYSTICK_RIGHT:
				game->player.dir_x = 0;
				game->player.dir_x += PLAYER_SPEED;
				break;
			}
		break;
		case SDL_JOYBUTTONUP:
			switch (event.jbutton.button) {
			case JOYSTICK_UP:
				game->player.dir_y = 0;
				if (key[JOYSTICK_DOWN])
					game->player.dir_y += PLAYER_SPEED;
				break;
			case JOYSTICK_DOWN:
				game->player.dir_y = 0;
				if (key[JOYSTICK_UP])
					game->player.dir_y -= PLAYER_SPEED;
				break;
			case JOYSTICK_LEFT:
				game->player.dir_x = 0;
				if (key[JOYSTICK_RIGHT])
					game->player.dir_x += PLAYER_SPEED;
				break;
			case JOYSTICK_RIGHT:
				game->player.dir_x = 0;
				if (key[JOYSTICK_LEFT])
					game->player.dir_x -= PLAYER_SPEED;
				break;
			}
		break;
		case SDL_JOYAXISMOTION:
			switch (event.jaxis.axis) {
			case 0: /* Left - Right stick axis. */
				if (event.jaxis.value < -16000) {
					game->player.dir_x = 0;
					game->player.dir_x -= PLAYER_SPEED;
				} else if (event.jaxis.value < -6400) {
					game->player.dir_x = 0;
					game->player.dir_x -= PLAYER_SPEED / 2;
				} else if (event.jaxis.value > 16000) {
					game->player.dir_x = 0;
					game->player.dir_x += PLAYER_SPEED;
				} else if (event.jaxis.value > 6400) {
					game->player.dir_x = 0;
					game->player.dir_x += PLAYER_SPEED / 2;
				} else
					game->player.dir_x = 0;
				break;
			case 1: /* Up - Down stick axis. */
				if (event.jaxis.value < -16000) {
					game->player.dir_y = 0;
					game->player.dir_y -= PLAYER_SPEED;
				} else if (event.jaxis.value < -6400) {
					game->player.dir_y = 0;
					game->player.dir_y -= PLAYER_SPEED / 2;
				} else if (event.jaxis.value > 16000) {
					game->player.dir_y = 0;
					game->player.dir_y += PLAYER_SPEED;
				} else if (event.jaxis.value > 6400) {
					game->player.dir_y = 0;
					game->player.dir_y += PLAYER_SPEED / 2;
				} else
					game->player.dir_y = 0;
				break;
			}
		break;
		case SDL_QUIT:
			game_terminate(0);
		}
	}
}
