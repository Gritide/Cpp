#include <iostream>
#include <string>
using namespace std;

#include "olcConsoleGameEngine.h"


class OneLoneCoder_FlappyBird : public olcConsoleGameEngine
{
public:
	OneLoneCoder_FlappyBird()
	{
		m_sAppName = L"Naruto";
	}

private:

	float fBirdPosition = 0.0f;
	float fBirdVelocity = 0.0f;
	float fBirdAcceleration = 0.0f;
	float fGravity = 100.0f;
	float fLevelPosition = 0.0f;

	float fSectionWidth;
	list<int> listSection;
	//collison
	bool bHasCollided = false;
	bool bResetGame = false;
	//scoring
	int nAttemptCount = 0;
	int nFlapCount = 0;
	int nMaxFlapCount = 0;


protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		listSection = { 0, 0, 0, 0 };
		//this is the obstacles if you set more zeroes blocks(obstaacles will be closing each other)     
		bResetGame = true;
		fSectionWidth = (float)ScreenWidth() / (float)(listSection.size() - 1);
		return true;
	}

	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (bResetGame)//by reset the game
		{
			bHasCollided = false;
			bResetGame = false;
			listSection = { 0, 0, 0, 0 };//the space between obstacles
			fBirdAcceleration = 0.0f;
			fBirdVelocity = 0.0f;
			fBirdPosition = ScreenHeight() / 2.0f;
			nFlapCount = 0;//count scores
			nAttemptCount++; //count every attempt
		}

		// Game
		if (bHasCollided)
		{
			// Do nothing until user releases space
			if (m_keys[VK_SPACE].bReleased)
				bResetGame = true;
		}//if it has collided than reset the game  by using space key
		else
		{

			if (m_keys[VK_SPACE].bPressed && fBirdVelocity >= fGravity / 10.0f)//  velocity greater than propositoon oof gravity down soo that means it has too be falling before its journey to make moore dificult
				//if you use space than its mooving up
			{
				fBirdAcceleration = 0.0f;
				fBirdVelocity = -fGravity / 4.0f;
				nFlapCount++;//when user use space key then increase the count
				if (nFlapCount > nMaxFlapCount) //if count is greater than count
					nMaxFlapCount = nFlapCount; // set the new count to max
			}
			else//falling due to gravity
				fBirdAcceleration += fGravity * fElapsedTime; 

			if (fBirdAcceleration >= fGravity)
				fBirdAcceleration = fGravity;

			fBirdVelocity += fBirdAcceleration * fElapsedTime;
			fBirdPosition += fBirdVelocity * fElapsedTime;
			fLevelPosition += 14.0f * fElapsedTime;

			if (fLevelPosition > fSectionWidth)
			{
				fLevelPosition -= fSectionWidth;
				listSection.pop_front();
				int i = rand() % (ScreenHeight() - 20);
				if (i <= 10) i = 0;
				listSection.push_back(i);
			}

			// Display
			Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

			// Draw Sections
			int nSection = 0;
			for (auto s : listSection)
			{
				if (s != 0)
				{  //bottom rectangle
 					Fill(nSection * fSectionWidth + 13 - fLevelPosition, ScreenHeight() - s, nSection * fSectionWidth + 15 - fLevelPosition, ScreenHeight(), PIXEL_SOLID, FG_BLUE);
					//top rectangle
					Fill(nSection * fSectionWidth + 13 - fLevelPosition, 0, nSection * fSectionWidth + 15 - fLevelPosition, ScreenHeight() - s - 15, PIXEL_SOLID, FG_BLUE);
				//for off set of console screen   , we need 10 for it doesnt fill whole section , we  want to offset the whole thing by the current position
				//this will give the impression that the level is scrolling smoothly past the bird, s is obstacle
				}
				nSection++;
			}

			int nBirdX = (int)(ScreenWidth() / 3.0f);

			// Collision Detection
			bHasCollided = fBirdPosition < 2 || fBirdPosition > ScreenHeight() - 2 ||
				m_bufScreen[(int)(fBirdPosition + 0) * ScreenWidth() + nBirdX].Char.UnicodeChar != L' ' ||
				m_bufScreen[(int)(fBirdPosition + 1) * ScreenWidth() + nBirdX].Char.UnicodeChar != L' ' ||
				m_bufScreen[(int)(fBirdPosition + 0) * ScreenWidth() + nBirdX + 6].Char.UnicodeChar != L' ' ||
				m_bufScreen[(int)(fBirdPosition + 1) * ScreenWidth() + nBirdX + 6].Char.UnicodeChar != L' ';
			//either bird has gone off the top of the screen ,,,, either has fallen off the bottom of the screen ,, or has intersected
			//with something other than a blank space
			// Draw Bird
			if (fBirdVelocity > 0)
			{
				DrawString(nBirdX, fBirdPosition + 0, L"\\\\\\");
				DrawString(nBirdX, fBirdPosition + 1, L"<\\\\\\=Q"); //falling and its wing going to be up
			}
			else
			{
				DrawString(nBirdX, fBirdPosition + 0, L"<///=Q");
				DrawString(nBirdX, fBirdPosition + 1, L"///");// it is flapping so wings going down
			}

			DrawString(1, 1, L"Attempt: " + to_wstring(nAttemptCount) + L" Score: " + to_wstring(nFlapCount) + L" High Score: " + to_wstring(nMaxFlapCount));
			//printing on screen coordinate 1 to 1
		}

		return true;
	}
};


int main()
{
	// Use olcConsoleGameEngine derived app
	OneLoneCoder_FlappyBird game;
	game.ConstructConsole(80, 48, 16, 16); //80characters wide 48 character high and each character 16 by 16 pixel
	game.Start();

	return 0;
}


//x,y position         dx,dy velocity    d^2x,d^2y   acceleration
// we dont need x bc its just mooving  up and down which y
//its has to falling before flapping again so birds has positive velocity




//kdlfphj;kdfhjkgdlhfjldfhljdfkihjlkdfhk'dfhk'dfkhkdfhjdf'khjd'lkfhj'lkdfh Q