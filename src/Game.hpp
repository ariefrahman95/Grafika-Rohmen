#ifndef GAME_HPP
#define GAME_HPP

// the main game object
class Game {

	public:
		// ctor-dtor
		Game();
		~Game();
		
		// to exit from the game
		const bool IsExit() const;
		void SetExit( const bool );
		
		// game loop methods
		void HandleInput();
		void Update();
		void Draw();
		
		// main game function
		void Run();
		
	private:
		Game( const Game& );
		Game& operator = ( const Game& );
		
		bool exit;
};

#endif