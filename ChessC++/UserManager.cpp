#include "UserManager.h"
#include "Input.h"

UserManager::UserManager()
{
	
}

void UserManager::ClickPiece()
{
	if (Input::MousePressed(MouseButton::LEFT))
	{
		clickedX = Input::MouseX();
		clickedY = Input::MouseY();
		isClicked = true;
	}
}
