#include "Game.hpp"
#include <graphics.h>
#include <iostream>
#include <Windows.h>
using namespace std;

Game::Game() {
	exit = false;
}

Game::~Game() {
}

void Game::HandleInput() {

	// -- insert any handle input here
	if (GetAsyncKeyState(VK_ESCAPE)) {
		cout << "Keluar deh..." << endl;
	} else {
		cout << "1";
	}
}

void Game::Update() {

	// -- insert any update here
	
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
	
	// -- insert any drawing here
	for ( int i = 0; i < getmaxx(); i++ ) {
		for ( int j = 0; j < getmaxy(); j++ ) {
			putpixel( i, j, i % 16 );
		}
	}
	
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