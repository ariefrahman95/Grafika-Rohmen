#ifndef GAME_HPP
#define GAME_HPP

#include "Canvas.hpp"

// the main game object
class Game {

	public:
		// ctor-dtor
		Game();
		~Game();
		
		// game loop methods
		void HandleInput();
		void Update();
		void Draw();
		
		// main game function
		void Run();
		
		// to exit from the game
		inline const bool IsExit() const;
		inline void SetExit( const bool exit );
		
	protected:
		// make the object non-copyable
		Game( const Game& );
		Game& operator = ( const Game& );
		
	private:
		Canvas canvas;
		
		bool exit;
};

#endif