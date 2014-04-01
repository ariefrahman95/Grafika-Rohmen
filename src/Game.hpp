#ifndef GAME_HPP
#define GAME_HPP

#include "Canvas.hpp"
#include "TimeBar.hpp"
#include "Pemandangan.hpp"
#include "Notification.hpp"
#include "Barrier.hpp"
#include "Car.hpp"

#define BKEY_LEFT 37
#define BKEY_RIGHT 39

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
        bool isStart;
		bool isPlaying;
        bool isInitialBg;
		
		TimeBar timeBar;
        Pemandangan pemandangan;
		Barrier wheel, wood, stone;
        Notification notif;
		Car car;
};

#endif