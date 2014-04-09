#include "Game.hpp"
#include <graphics.h>
#include <iostream>
#include <Windows.h>
using namespace std;

Game::Game() : wheel(WHEEL), wood(WOOD), stone(STONE) {
	isPlaying = false;
	isGameOver = false;
	exit = false;
    isInitialBg = false;
}

Game::~Game() {
}

void Game::HandleInput() {
	if (keypressed(BKEY_LEFT)) {
		if (!isPlaying && !timeBar.IsTimeUp() && !isGameOver) {
			isPlaying = true;
		}
		timeBar.Move(-1);
		car.Move(-1);
	}

	if (keypressed(BKEY_RIGHT)) {
		if (!isPlaying && !timeBar.IsTimeUp() && !isGameOver) {
			isPlaying = true;
		}
		timeBar.Move(1);
		car.Move(1);
	}
}

void Game::Update() {
	if (isPlaying) {
		timeBar.Update();
		
		wheel.Update();
		wood.Update();
		stone.Update();
        
		pemandangan.Update();
		
		int X1 = (car.carS.at(3).getT(0).x + car.carS.at(3).getT(3).x)/2 - wheel.wheel[0].C.x;
		int X2 = (car.carS.at(3).getT(0).x + car.carS.at(3).getT(3).x)/2 - (wood.wood[0].P0.x + wood.wood[3].P0.x)/2;
		int X3 = (car.carS.at(3).getT(0).x + car.carS.at(3).getT(3).x)/2 - (stone.stone[1].P0.x + stone.stone[2].P0.x)/2;
		if (
			timeBar.IsTimeUp() 
			|| 
			(
				(wheel.wheel[0].C.y > 342 && ABS(X1) < 100 && wheel.IsWheelFront()) 
				|| 
				(wood.wood[0].P0.y > 342 && ABS(X2) < 100 && wood.IsWoodFront()) 
				|| 
				(stone.stone[0].P0.y > 342 && ABS(X3) < 100 && stone.IsStoneFront())
			)
		) {
			isPlaying = false;
			isGameOver = true;
		}
	} else if (!isPlaying && (isGameOver || timeBar.IsTimeUp())) {
		notif.Update();
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
	
	if (!wheel.IsWheelFront() || !wood.IsWoodFront() || !stone.IsStoneFront()) {
		car.Draw(canvas);
		wheel.Draw(canvas);
		wood.Draw(canvas);
		stone.Draw(canvas);
	} else {
		wheel.Draw(canvas);
		wood.Draw(canvas);
		stone.Draw(canvas);
		car.Draw(canvas);
	}
	
	timeBar.Draw(canvas);
	
	if (timeBar.IsTimeUp() || isGameOver) {
		notif.Draw(canvas);
	}
	
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