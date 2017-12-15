#include <tool.h>
#include <SDL2/SDL.h>

const uint dmp = 277;

const uint hm = 32;

const uint hr = 100;

float hmp;

const uchar map[25] = {
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1
};

int main(int argc, char* argv[]){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;


	if(SDL_CreateWindowAndRenderer(320, 200, 0, &window, &renderer) < 0){
		printf( "SDL could not create a window! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}

	SDL_bool done=SDL_TRUE;

	while(done){
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

		hmp=dmp*(hm/48.0);
		unsigned int i;
		for(i=0; i<160; i++){
			SDL_RenderDrawLine(renderer, i, hr-hmp/2, i, hr+hmp/2);
		}

		SDL_SetRenderDrawColor(renderer, 200, 0, 0, SDL_ALPHA_OPAQUE);

		hmp=dmp*(hm/80.0);
		for(; i<320; i++){
			SDL_RenderDrawLine(renderer, i, hr-hmp/2, i, hr+hmp/2);
		}

		SDL_RenderPresent(renderer);

		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				done=SDL_FALSE;
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}