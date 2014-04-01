#include "Game.hpp"
#include <graphics.h>
#include <iostream>
#include <Windows.h>
using namespace std;

Game::Game() : wood(WOOD) {
	isPlaying = false;
	exit = false;
    isInitialBg = false;
}

Game::~Game() {
}

void Game::HandleInput() {
	if (keypressed(BKEY_LEFT)) {
		if (!isPlaying && !timeBar.IsTimeUp()) {
			isPlaying = true;
		}
		timeBar.Move(-1);
		car.Move(-1);
	}

	if (keypressed(BKEY_RIGHT)) {
		if (!isPlaying && !timeBar.IsTimeUp()) {
			isPlaying = true;
		}
		timeBar.Move(1);
		car.Move(1);
	}
}

void Game::Update() {
	if (isPlaying) {
		timeBar.Update();
		wood.Update();
        pemandangan.Update();
		if (timeBar.IsTimeUp()) {
			isPlaying = false;
		}
	}
}

const bool Game::IsExit() const {
	return exit;
}

void Game::SetExit( const bool exit ) {
	this->exit = exit;
}
		
void Game::Draw() {
	// begin drawing
	canvas.BeginDraw();
	
    pemandangan.Draw(canvas);
	wood.Draw(canvas);
	car.Draw(canvas);
	
	timeBar.Draw(canvas);
	
	/*// drawing testing by Tito
	for ( int i = 0; i < getmaxx(); i++ ) {
		for ( int j = 0; j < getmaxy(); j++ ) {
			putpixel( i, j, i % 16 );
		}
	}*/
	
	// end drawing
	canvas.EndDraw();
}

void Game::Run() {
	while ( !IsExit() ) {
		
		HandleInput();
		Update();
		Draw();
		
		// sleep to make game run at 30 FPS
		//delay( 1000 / 30);
	}
}