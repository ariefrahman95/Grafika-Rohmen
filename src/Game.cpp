#include "Game.hpp"
#include <graphics.h>
#include <iostream>
#include <Windows.h>
using namespace std;

Game::Game() {
	isPlaying = false;
	exit = false;
}

Game::~Game() {
}

void Game::HandleInput() {
	if (keypressed(KEY_LEFT)) {
		if (!isPlaying) {
			isPlaying = true;
		}
	}
	if (keypressed(KEY_RIGHT)) {
		if (!isPlaying) {
			isPlaying = true;
		}
	}
}

void Game::Update() {
	if (isPlaying) {
		timeBar.Update();
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
		delay( 1000 / 30 );
	}
}