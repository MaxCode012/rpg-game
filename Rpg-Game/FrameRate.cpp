#include "FrameRate.h"

FrameRate::FrameRate() : timer(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	font.loadFromFile("Assets/fonts/arial.ttf");
	frameRateText.setFont(font);
}

void FrameRate::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= 500) 
	{

	std::string frameRateString = "FPS: " + std::to_string((int)(1000 / deltaTime));

	frameRateText.setString(frameRateString);
	timer = 0;
	}

}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);

}
