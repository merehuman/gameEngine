//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "CameraDemoInput.h"
#include "CameraMan.h"
#include "Clip.h"
#include "AnimController.h"

namespace Azul
{
	//extern bool isPaused;
	//extern bool playForward;
	//extern bool loop;
	//extern float playbackSpeed;
	//extern ClipType currentClip;
	//extern bool switchAnim;
	bool aKeyPreviousState = false;

	bool IsKeyPressedOnce(int virtualKey, bool& previousState) {
		bool currentState = (GetKeyState(virtualKey) & 0x8000) != 0;

		if (currentState && !previousState) {
			previousState = true;
			return true;
		}

		if (!currentState) {
			previousState = false;
		}

		return false;
	}

	void CameraDemoInput()
	{	
		//if (IsKeyPressedOnce('A', aKeyPreviousState)) 
		//{
		//	if (switchAnim == false)
		//	{
		//		switchAnim = true;
		//	}
		//	else if (switchAnim == true)
		//	{
		//		switchAnim = false;
		//	}
		//}

//something here to go to camerman set current

		//static bool prevPausedState = isPaused;
		
		// Change current clip
		//if ((GetKeyState('1') & 0x8000)) currentClip = ClipType::WALK;
		//if ((GetKeyState('2') & 0x8000)) currentClip = ClipType::RUN;
		//if ((GetKeyState('3') & 0x8000)) currentClip = ClipType::IDLE;
		//if ((GetKeyState('4') & 0x8000)) currentClip = ClipType::DIE;

		// Toggle pause/play
		//if ((GetKeyState('P') & 0x8000))
		//{
		//	if (!prevPausedState)
		//	{
		//		isPaused = !isPaused;
		//		prevPausedState = true;
		//	}
		//}
		//else
		//{
		//	prevPausedState = false;
		//}

		//// Change playback direction
		//if ((GetKeyState('F') & 0x8000)) // Forward playback
		//{
		//	playForward = true;
		//}

		//if ((GetKeyState('B') & 0x8000)) // Backward playback
		//{
		//	playForward = false;
		//}

		//// Adjust playback speed
		//if ((GetKeyState('U') & 0x8000)) // Increase speed
		//{
		//	playbackSpeed += 0.1f;
		//	if (playbackSpeed > 5.0f) // Cap speed to a maximum
		//	{
		//		playbackSpeed = 5.0f;
		//	}
		//}

		//if ((GetKeyState('D') & 0x8000)) // Decrease speed
		//{
		//	playbackSpeed -= 0.1f;
		//	if (playbackSpeed < 0.1f) // Cap speed to a minimum
		//	{
		//		playbackSpeed = 0.1f;
		//	}
		//}
		//static bool loopKeyPressed = false;

		//if ((GetKeyState('L') & 0x8000)) // Key is pressed
		//{
		//	if (!loopKeyPressed) // First press
		//	{
		//		loop = !loop; // Toggle loop
		//		loopKeyPressed = true; // Mark key as processed
		//	}
		//}
		//else
		//{
		//	loopKeyPressed = false; // Reset when key is released
		//}




		if((GetKeyState('I') & 0x8000))
		{
			Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);

			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm
			//	tar = obj;

			pos = pos + 0.03f * forwardNorm;
			//tar = tar + 0.03f * forwardNorm;
			up = up + 0.03f * forwardNorm;

			pCam->SetHelper(up, tar, pos);
		}

		if((GetKeyState('O') & 0x8000))
		{
			Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);

			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm
			//tar = obj;

			pos = pos - 0.03f * forwardNorm;
			up = up - 0.03f * forwardNorm;

			pCam->SetHelper(up, tar, pos);

		}


		if((GetKeyState(VK_RIGHT) & 0x8000))
		{
			Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);

			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm
			//	tar = obj;

			Trans T1(tar);
			Trans nT1(-tar);

			Rot R1;
			R1.set(Axis::AxisAngle, upNorm, +0.03f);

			Mat4 M = nT1 * R1 * T1;

			up = Vec4(up, 1) * M;
			pos = Vec4(pos, 1) * M;
			tar = Vec4(tar, 1) * M;

			pCam->SetHelper(up, tar, pos);
		}



		if((GetKeyState(VK_LEFT) & 0x8000))
		{
			Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);

			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm

		//	tar = obj;

			Trans T1(tar);
			Trans nT1(-tar);

			Rot R1;
			R1.set(Axis::AxisAngle, upNorm, -0.03f);

			Mat4 M = nT1 * R1 * T1;

			up = Vec4(up, 1) * M;
			pos = Vec4(pos, 1) * M;
			tar = Vec4(tar, 1) * M;

			pCam->SetHelper(up, tar, pos);
		}

		if((GetKeyState(VK_DOWN) & 0x8000))
		{
			Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);

			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			//	tar = obj;


				// OK, now 3 points... pos, tar, up
				//     now 3 normals... upNorm, forwardNorm, rightNorm

			Trans T1(tar);
			Trans nT1(-tar);
			Rot R1;
			R1.set(Axis::AxisAngle, rightNorm, 0.03f);

			Mat4 M = nT1 * R1 * T1;

			up = Vec4(up, 1) * M;
			pos = Vec4(pos, 1) * M;
			tar = Vec4(tar, 1) * M;

			pCam->SetHelper(up, tar, pos);
		}

		if((GetKeyState(VK_UP) & 0x8000))
		{
			Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);

			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm
			//tar = obj;

			Trans T1(tar);
			Trans nT1(-tar);
			Rot R1;
			R1.set(Axis::AxisAngle, rightNorm, -0.03f);

			Mat4 M = nT1 * R1 * T1;

			up = Vec4(up, 1) * M;
			pos = Vec4(pos, 1) * M;
			tar = Vec4(tar, 1) * M;

			pCam->SetHelper(up, tar, pos);
		}

	}
}

// --- End of File ---
