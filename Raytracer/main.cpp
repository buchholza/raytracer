#include <iostream>
#include <SDL.h>
#include <time.h>

#include "glm/glm.hpp"

#include "Camera.h"
#include "DirectionalLight.h"
#include "FinitePlane.h"
#include "Light.h"
#include "Plane.h"
#include "PointLight.h"
#include "Scene.h"
#include "Sphere.h"

// Screen width and height
const int WIDTH = 640;
const int HEIGHT = 480;

Scene setupScene()
{
	Scene scene;

	scene.objects->push_back(std::unique_ptr<Object>(new Sphere(glm::vec3(255, 105, 180), 0.18f, glm::vec3(0, 0, -5), 1)));
	scene.objects->push_back(std::unique_ptr<Object>(new Sphere(glm::vec3(15, 105, 15), 0.18f, glm::vec3(2.5f, 0, -5), 0.5f)));
	//scene.objects->push_back(std::unique_ptr<Object>(new Plane(glm::vec3(255, 255, 255), 0.18f, glm::vec3(0, -1, -3), glm::vec3(0, 1, 0))));
	scene.objects->push_back(std::unique_ptr<Object>(new FinitePlane(glm::vec3(255, 255, 255), 0.18f, glm::vec3(0, -1, -5), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1), 7.5f, glm::vec3(1, 0, 0), 5)));

	scene.lights->push_back(std::unique_ptr<Light>(new DirectionalLight(glm::vec3(255, 255, 255), 20, glm::vec3(-1, -1, 0))));
	//scene.lights->push_back(std::unique_ptr<Light>(new PointLight(glm::vec3(255, 255, 255), 255, glm::vec3(0, 3, -5))));

	Camera camera;
	scene.camera = camera;

	return scene;
}

void showScene(Scene scene, SDL_Renderer *renderer)
{
	glm::vec3 *framebuffer = scene.render();

	glm::vec3 *pixel = framebuffer;
	for(uint32_t y = 0; y < HEIGHT; y++)
	{
		for(uint32_t x = 0; x < WIDTH; x++)
		{
			uint8_t r = (uint8_t)pixel->x;
			uint8_t g = (uint8_t)pixel->y;
			uint8_t b = (uint8_t)pixel->z;

			SDL_SetRenderDrawColor(renderer, r, g, b, (uint8_t)255);
			SDL_RenderDrawPoint(renderer, x, y);

			pixel++;
		}
	}

	SDL_RenderPresent(renderer);
	delete[] framebuffer;
}

int main(int argc, char* argv[])
{
	// Initialize everything in SDL and handle errors
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
	}

	// Create a window and handle errors
	SDL_Window* window = SDL_CreateWindow("Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if(window == NULL)
	{
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if(renderer == NULL)
	{
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	Scene scene = setupScene();
	showScene(scene, renderer);

	// Keep polling for events until SDL_QUIT event is received
	SDL_Event windowEvent;
	while(true)
	{
		if(SDL_PollEvent(&windowEvent))
		{
			if(windowEvent.type == SDL_QUIT)
			{
				break;
			}
		}
	}

	// Destroy window and clean up SDL
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}