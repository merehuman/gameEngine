//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#include "Game.h"
#include "MathEngine.h"
#include "CameraDemoInput.h"

#include "ShaderObject_Uber.h"
#include "Manager_Uber.h"
#include "GraphicsObject_Uber.h"

#include "GameObjectBasic.h"
#include "Anim.h"
#include "AnimController.h"
#include "Sprite.h"
#include "FontSprite.h"
#include "ShaderMappings.h"
#include "Mixer.h"
#include "WorldCompute.h"


namespace Azul
{

	Bone HackLocalBone[15];
	Mat4 HackWorld[8];

	// Todo: clean up
	AnimController *pAnimController;
	AnimController* pAnimControllerRigid;
	FontSprite* pFontSprite1;

	//-----------------------------------------------------------------------------
	//  Game::Game()
	//		Game Engine Constructor
	//-----------------------------------------------------------------------------

	Game::Game(const char *const pName, int width, int height)
	: Engine(pName, width, height)
	{
		this->globalTimer.Tic();
		this->intervalTimer.Tic();
	}

	//-----------------------------------------------------------------------------
	//  Game::~Game()
	//		Game Engine destructor
	//-----------------------------------------------------------------------------
	Game::~Game()
	{
	}

	//-----------------------------------------------------------------------------
	// Game::LoadContent()
	//		Allows you to load all content needed for your engine,
	//	    such as objects, graphics, etc.
	//-----------------------------------------------------------------------------
	bool Game::LoadContent()
	{
		ShaderObjectNodeMan::Create();
		MeshNodeMan::Create();
		GameObjectMan::Create();
		TexNodeMan::Create();
		CameraMan::Create();
		ImageMan::Create();
		GlyphMan::Create();
		SkelMan::Create();
		ClipMan::Create();
		JointTableMan::Create();
		HierarchyTableMan::Create();

		//---------------------------------------------------------------------------------------------------------
		// 3D perspective Camera
		//---------------------------------------------------------------------------------------------------------
		{
		Camera *pCam3D = new Camera(Camera::Type::PERSPECTIVE_3D);

		pCam3D->setViewport(0, 0, this->mWindowWidth, this->mWindowHeight);

		pCam3D->setPerspective(35.0f,
							   float(pCam3D->getScreenWidth()) / float(pCam3D->getScreenHeight()),
							   1.0f,
							   100000.0f);

		pCam3D->setOrientAndPosition(Vec3(0.0f, 1.0f, 0.0f),
									Vec3(0.0f, 100.0f, 0.0f),
									Vec3(-1.0f, 100.0f, 500.0f));

		//pCam3D->setOrientAndPosition(Vec3(0.0f, 1.0f, 0.0f),
		//							Vec3(0.0f, 2.0f, 0.0f),
		//							Vec3(0.0f, 2.0f, 12.0f));

		pCam3D->updateCamera();
		CameraMan::Add(Camera::Name::CAMERA_0, pCam3D);
		CameraMan::SetCurrent(Camera::Name::CAMERA_0, Camera::Type::PERSPECTIVE_3D);
		}

		//---------------------------------------------------------------------------------------------------------
		// 2D orthographic Camera
		//---------------------------------------------------------------------------------------------------------
		{
		Camera *pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

		pCam2D->setViewport(0, 0, this->mWindowWidth, this->mWindowHeight);
		pCam2D->setOrthographic((float)-pCam2D->getScreenWidth() / 2.0f,
								(float)pCam2D->getScreenWidth() / 2.0f,
								(float)-pCam2D->getScreenHeight() / 2.0f,
								(float)pCam2D->getScreenHeight() / 2.0f,
								1.0f,
								1000.0f);
		pCam2D->setOrientAndPosition(Vec3(0.0f, 1.0f, 0.0f),
									 Vec3(0.0f, 0.0f, -1.0f),
									 Vec3(0.0f, 0.0f, 2.0f));
		pCam2D->updateCamera();
		CameraMan::Add(Camera::Name::CAMERA_1, pCam2D);
		CameraMan::SetCurrent(Camera::Name::CAMERA_1, Camera::Type::ORTHOGRAPHIC_2D);
		}

		// --------------------------------
		//   Mesh 
		// --------------------------------

		MeshNodeMan::Add("spritemesh.m.proto.azul", Mesh::Name::SPRITE);
		MeshNodeMan::Add("silly_dancing.m.proto.azul", Mesh::Name::Dancing);
		MeshNodeMan::Add("chickenbot.m.proto.azul", Mesh::Name::ChickenBot);

		// --------------------------------
		//   Joint
		// --------------------------------

		JointTableMan::Add("silly_dancing.j.proto.azul", JointTable::Name::Dancing);
		JointTableMan::Add("chickenbot.j.proto.azul", JointTable::Name::ChickenBot);

		// --------------------------------
		//   Hierarchy
		// --------------------------------

		HierarchyTableMan::Add("silly_dancing.h.proto.azul", HierarchyTable::Name::Dancing);
		HierarchyTableMan::Add("chickenbot.h.proto.azul", HierarchyTable::Name::ChickenBot);

		// --------------------------------
		//   Skeleton
		// --------------------------------

		SkelMan::Add("silly_dancing.s.proto.azul", Skel::Name::Dancing);
		SkelMan::Add("chickenbot.s.proto.azul", Skel::Name::ChickenBot);

		// --------------------------------
		//   Clip
		// --------------------------------

		ClipMan::Add("silly_dancing.a.proto.azul", Clip::Name::Dancing, Skel::Name::Dancing);
		ClipMan::Add("chickenbot.a.proto.azul", Clip::Name::Walk_ChickenBot, Skel::Name::ChickenBot);

		// --------------------------------
		//  Shader
		// --------------------------------

		ShaderObjectNodeMan::Add(new ShaderObject_Sprite(ShaderObject::Name::Sprite));
		ShaderObjectNodeMan::Add(new ShaderObject_ColorByVertex(ShaderObject::Name::ColorByVertex));
		ShaderObjectNodeMan::Add(new ShaderObject_FlatTexture(ShaderObject::Name::FlatTexture));
		ShaderObjectNodeMan::Add(new ShaderObject_LightTexture(ShaderObject::Name::LightTexture));
		ShaderObjectNodeMan::Add(new ShaderObject_ConstColor(ShaderObject::Name::ConstColor));
		ShaderObjectNodeMan::Add(new ShaderObject_SkinFlatTexture(ShaderObject::Name::SkinFlatTexture));
		ShaderObjectNodeMan::Add(new ShaderObject_SkinLightTexture(ShaderObject::Name::SkinLightTexture));
		ShaderObjectNodeMan::Add(new ShaderObject_BasicCompute(ShaderObject::Name::BasicCompute));
		ShaderObjectNodeMan::Add(new ShaderObject_Mixer(ShaderObject::Name::MixerCompute));
		ShaderObjectNodeMan::Add(new ShaderObject_World(ShaderObject::Name::WorldCompute));

		// --------------------------------
		//  Texture
		// --------------------------------

		TexNodeMan::Add("silly_dancing.t.proto.azul", TextureObject::Name::Dancing);
		TexNodeMan::Add("chickenbot.t.proto.azul", TextureObject::Name::ChickenBot);
		TexNodeMan::Add("red_alien.t.proto.azul", TextureObject::Name::RedAlien);

		// -----------------------------------
		//  Image
		// -----------------------------------
		ImageMan::Add(Image::Name::RedAlien, TextureObject::Name::RedAlien, Rect(0.0f, 0.0f, 440.f, 320.0f));

		// ---------------------------------------------
		//  Font - load xml
		// ---------------------------------------------
		TexNodeMan::Add("FontArial36.t.proto.azul", TextureObject::Name::FontArial36);
		GlyphMan::Add("MetricsArial36.xml.proto.azul", TextureObject::Name::FontArial36);


		// ------------------------------------------------
		// Create Animation - needs love and refactoring
		// ------------------------------------------------

		// Anim needs skeleton
		//		po - pointer owned
		//		pt - pointer transient being owned by someone else to own
		Color color(0.0f, 0.0f, 0.0f, 1.0f);
		Vec3 poLightPos = Vec3(1.0f, 1.0f, 1.0f);
		Vec3 poLightColor = Vec3(200.0f, 50.0f, 50.0f);

		//demo font
		{
			GraphicsObject* pGraphicsFont = new GraphicsObject_Sprite(
				Mesh::Name::SPRITE,
				ShaderObject::Name::Sprite,
				Image::Name::Not_Initialized,
				Rect(100, 100, 100, 100));
			
			pFontSprite1 = new FontSprite(pGraphicsFont);
			GameObjectMan::Add(pFontSprite1, GameObjectMan::GetRoot());
			
			pFontSprite1->Set(FontSprite::Name::TestMessage,
				"h e l l o",
				Glyph::Name::Arial36pt,
				100.0f,
				100.0f,
				color);
		}

		//demo sprite
		{
			GraphicsObject* pGraphicsSprite = new GraphicsObject_Sprite(
				Mesh::Name::SPRITE,
				ShaderObject::Name::Sprite,
				Image::Name::RedAlien,
				Rect(600, 400, 220.0f, 160.0f));
			Sprite* pSprite = new Sprite(pGraphicsSprite);
			GameObjectMan::Add(pSprite, GameObjectMan::GetRoot());
		}

		//demo rigid body
		{				
			//anim setup
			HierarchyTable* pHierarchyTable = HierarchyTableMan::Find(HierarchyTable::Name::ChickenBot);
			Skeleton* ptSkeleton = new Skeleton(Clip::Name::Walk_ChickenBot);
			assert(ptSkeleton);

			Mixer* ptMixer = new Mixer(ptSkeleton->GetClip());
			assert(ptMixer);

			WorldCompute* ptWorldCompute = new WorldCompute(ptMixer, pHierarchyTable);
			assert(ptWorldCompute);

			Anim* ptAnim = new Anim(ptSkeleton, ptMixer);
			assert(ptAnim);

			//mesh setup
			GraphicsObject_SkinFlatTexture* pGraphicsRigid = new GraphicsObject_SkinFlatTexture(
				Mesh::Name::ChickenBot,
				ShaderObject::Name::SkinFlatTexture,
				TextureObject::Name::ChickenBot,
				ptMixer,
				ptWorldCompute);

			GameObjectAnimSkin* pGameAnimRigid = new GameObjectAnimSkin(pGraphicsRigid, ptMixer, ptWorldCompute);
			pGameAnimRigid->SetName("ChickenBot");
			pGameAnimRigid->SetScale(1000.0f, 1000.0f, 1000.0f);
			pGameAnimRigid->SetTrans(100.0f, 0.0f, 0.0f);
			pGameAnimRigid->cur_rot_y = 180.0f;
			pGameAnimRigid->poQuat->set(0.0f, 1.0f, 0.0f, 0.0f);
			GameObjectMan::Add(pGameAnimRigid, GameObjectMan::GetRoot());

			AnimTime delta(AnimTime::Duration::FILM_24_FRAME);
			pAnimControllerRigid = new AnimController(ptAnim, 0.2f * delta);
			assert(pAnimControllerRigid);
		}

		//demo procedural mesh generation
		{

		}

		//demo skinned mesh
		{
			HierarchyTable* pHierarchyTable1 = HierarchyTableMan::Find(HierarchyTable::Name::Dancing);

			Skeleton* ptSkeleton1 = new Skeleton(Clip::Name::Dancing);
			assert(ptSkeleton1);

			// Setup Compute shaders data
			Mixer* ptMixer1 = new Mixer(ptSkeleton1->GetClip());
			assert(ptMixer1);

			WorldCompute* ptWorldCompute1 = new WorldCompute(ptMixer1, pHierarchyTable1);
			assert(ptWorldCompute1);

			Anim* ptAnim1 = new Anim(ptSkeleton1, ptMixer1);
			assert(ptAnim1);

			// Skin Mesh
			GameObjectAnimSkin* pGameSkin1;
			GraphicsObject_SkinLightTexture* pGraphicsSkin1;

			pGraphicsSkin1 = new GraphicsObject_SkinLightTexture(Mesh::Name::Dancing,
				ShaderObject::Name::SkinLightTexture,
				TextureObject::Name::Dancing,
				ptMixer1,
				ptWorldCompute1,
				poLightPos,
				poLightColor);

			pGameSkin1 = new GameObjectAnimSkin(pGraphicsSkin1, ptMixer1, ptWorldCompute1);
			pGameSkin1->SetName("Dancing");
			//pGameSkin1->delta_y = 0.005f;
			pGameSkin1->SetScale(100, 100, 100);
			pGameSkin1->SetTrans(0, -25, 0);
			GameObjectMan::Add(pGameSkin1, GameObjectMan::GetRoot());

			AnimTime delta(AnimTime::Duration::FILM_24_FRAME);
			pAnimController = new AnimController(ptAnim1, 0.2f * delta);
			assert(pAnimController);
		}

		return true;
	}


	//-----------------------------------------------------------------------------
	// Game::Update()
	//      Called once per frame, update data, tranformations, etc
	//      Use this function to control process order
	//      Input, AI, Physics, Animation, and Graphics
	//-----------------------------------------------------------------------------
	void Game::Update(float)
	{
		this->intervalTimer.Toc();
		this->intervalTimer.Tic();

		// -----------------------
		// Read inputs
		// -----------------------
		CameraDemoInput();

		// ------------------------------------
		// Camera update
		// ------------------------------------

		Camera *pCam3D = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);
		pCam3D->updateCamera();

		Camera *pCam2D = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
		pCam2D->updateCamera();

		//print 3d cam position
		//Vec3 camPosUp;
		//pCam3D->getUp(camPosUp);
		//Trace::out("Camera 3D Up: %f, %f, %f\n", camPosUp.x(), camPosUp.y(), camPosUp.z());
		//Vec3 camPosLook;
		//pCam3D->getLookAt(camPosLook);
		//Trace::out("Camera 3D Look: %f, %f, %f\n", camPosLook.x(), camPosLook.y(), camPosLook.z());
		//Vec3 camPosPos;
		//pCam3D->getPos(camPosPos);
		//Trace::out("Camera 3D Position: %f, %f, %f\n", camPosPos.x(), camPosPos.y(), camPosPos.z());

		// ------------------------------------
		// Animate Me
		// ------------------------------------
		if(pAnimController)
		{
			pAnimController->Update();
		}
		if (pAnimControllerRigid)
		{
			pAnimControllerRigid->Update();
		}

		// ------------------------------------
		// Update GameObjects
		// ------------------------------------
		GameObjectMan::Update(this->globalTimer.Toc());

	}

	//-----------------------------------------------------------------------------
	// Game::Render()
	//		This function is called once per frame
	//	    Use this for draw graphics to the screen.
	//      Only do rendering here
	//-----------------------------------------------------------------------------
	void Game::Render()
	{
		this->SetDefaultTargetMode();

		GameObjectMan::Draw();
	}

	//-----------------------------------------------------------------------------
	// Game::UnLoadContent()
	//       unload content (resources loaded above)
	//       unload all content that was loaded before the Engine Loop started
	//-----------------------------------------------------------------------------
	void Game::UnloadContent()
	{
		HierarchyTableMan::Destroy();
		JointTableMan::Destroy();
		ClipMan::Destroy();
		SkelMan::Destroy();
		GlyphMan::Destroy();
		ImageMan::Destroy();
		CameraMan::Destroy();
		ShaderObjectNodeMan::Destroy();
		MeshNodeMan::Destroy();
		GameObjectMan::Destroy();
		TexNodeMan::Destroy();
		DirectXDeviceMan::Destroy();

		delete pAnimController;
		delete pAnimControllerRigid;


	}

	//------------------------------------------------------------------
	// Game::ClearBufferFunc()
	// Allows user to change the way the clear buffer function works
	// 
	// Clear the color and depth buffers.
	//------------------------------------------------------------------
	void Game::ClearDepthStencilBuffer()
	{
#ifdef _DEBUG
		const Vec4 ClearColor = WindowColors::White;
#else
		const Vec4 ClearColor = WindowColors::Wheat;
#endif
		float clearDepth = 1.0f;
		uint8_t clearStencil = 0;

		this->mStateRenderTargetView.Clear(ClearColor);
		this->mDepthStencilView.Clear(clearDepth, clearStencil);
	}

}

// --- End of File ---
