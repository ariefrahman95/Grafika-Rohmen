#include "Game.hpp"
#include <graphics.h>
#include <iostream>
#include <ctime>
using namespace std;

Game::Game() {
	exit = false;
}

Game::~Game() {
}

const bool Game::IsExit() const {
	return exit;
}

void Game::SetExit( const bool e ) {
	exit = e;
}

void Game::HandleInput() {
	cout << "Input" << endl;
}

void Game::Update() {
	cout << "Update" << endl;
}

void Game::Draw() {
	cleardevice();
	for ( int i = 0; i < 16; i++ ) {
		setcolor( i );
		rectangle( i, 0, i + 1, getmaxy() );
	}
}

void Game::Run() {
	int gd = DETECT, gm = 0;
	initgraph( &gd, &gm, "" );
	
	while ( !IsExit() ) {
	
		clock_t clkstart = clock();
	
		HandleInput();
		Update();
		Draw();
		
		clock_t clkend = clock();
		
		// sleep for (1000 / 30) ms - time spent for loop methods
		int elapsedTimeMilis = (int)( ( clkend - clkstart ) / ( CLOCKS_PER_SEC / 1000 ) );
		delay( (1000 / 30)  - elapsedTimeMilis );
	}
	
	closegraph();
}