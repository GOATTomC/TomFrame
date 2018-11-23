#include <TomFrame.h>

class Game : public TomFrame::Application 
{
public:
	Game() 
	{

	}

	~Game()
	{

	}
};

TomFrame::Application* TomFrame::CreateApplication()
{
	return new Game();
}