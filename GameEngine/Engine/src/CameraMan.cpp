//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "CameraMan.h"
#include "CameraNull.h"
#include "ManBase.h"
#include "DLinkMan.h"

namespace Azul
{
	CameraMan *CameraMan::posInstance = nullptr;

	//----------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------
	CameraMan::CameraMan(int reserveNum, int reserveGrow)
	: ManBase(new DLinkMan(), new DLinkMan(), reserveNum, reserveGrow)
	{
	// Preload the reserve
	this->proFillReservedPool(reserveNum);

	// initialize derived data here
	Camera *pCam = new CameraNull();
	assert(pCam);
	this->poNodeCompare = new CameraNode();
	assert(this->poNodeCompare);
	this->poNodeCompare->Set(Camera::Name::NullCamera, pCam);
	}

	CameraMan::~CameraMan()
	{
	delete this->poNodeCompare;
	this->poNodeCompare = nullptr;

	// iterate through the list and delete
	Iterator *pIt = this->baseGetActiveIterator();

	DLink *pNode = pIt->First();

	// Walk through the nodes
	while(!pIt->IsDone())
	{
		CameraNode *pDeleteMe = (CameraNode *)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}

	pIt = this->baseGetReserveIterator();

	pNode = pIt->First();

	// Walk through the nodes
	while(!pIt->IsDone())
	{
		CameraNode *pDeleteMe = (CameraNode *)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}
	}

	void CameraMan::SetCurrent(const Camera::Name name, Camera::Type type)
	{
		CameraMan *pCamMan = CameraMan::privGetInstance();
		assert(pCamMan);

		Camera *pCam = CameraMan::Find(name);
	assert(pCam);

		// w1(7)
		switch(type)
		{
		case Camera::Type::PERSPECTIVE_3D:
			assert(pCam->getType() == Camera::Type::PERSPECTIVE_3D);
			pCamMan->pCamPerspective = pCam;
			break;

		case Camera::Type::ORTHOGRAPHIC_2D:
			assert(pCam->getType() == Camera::Type::ORTHOGRAPHIC_2D);
			pCamMan->pCamOrthographic = pCam;
			break;

		default:
			assert(false);
			break;
		}
	}

	Camera *CameraMan::GetCurrent(Camera::Type type)
	{
		Camera *pCam = nullptr;
		switch(type)
	{
		case Camera::Type::PERSPECTIVE_3D:
			pCam = CameraMan::privGetInstance()->pCamPerspective;
			break;

		case Camera::Type::ORTHOGRAPHIC_2D:
			pCam = CameraMan::privGetInstance()->pCamOrthographic;
			break;

		default:
			assert(false);
			break;
		}

		assert(pCam != nullptr);
		return pCam;
	}

	//----------------------------------------------------------------------
	// Static Methods
	//----------------------------------------------------------------------
	void CameraMan::Create(int reserveNum, int reserveGrow)
	{
	// make sure values are ressonable 
	assert(reserveNum >= 0);
	assert(reserveGrow > 0);

	// initialize the singleton here
	assert(posInstance == nullptr);

	// Do the initialization
	if(posInstance == nullptr)
	{
		posInstance = new CameraMan(reserveNum, reserveGrow);
	}
	}

	void CameraMan::Destroy()
	{
	CameraMan *pMan = CameraMan::privGetInstance();
	assert(pMan != nullptr);
	AZUL_UNUSED_VAR(pMan);

	delete CameraMan::posInstance;
	CameraMan::posInstance = nullptr;
	}

	Camera *CameraMan::Add(Camera::Name name, Camera *pCam)
	{
	CameraMan *pMan = CameraMan::privGetInstance();

	assert(pCam);

	CameraNode *pNode = (CameraNode *)pMan->baseAddToFront();
	assert(pNode != nullptr);

	// Initialize the date
	pNode->Set(name, pCam);

		return pNode->GetCamera();
	}

	CameraNode *CameraMan::FindNode(Camera *pCam)
	{
		assert(pCam);

		CameraMan *pMan = CameraMan::privGetInstance();
		assert(pMan != nullptr);

		// Compare functions only compares two Nodes
		pMan->poNodeCompare->Set(pCam);

		CameraNode *pData = (CameraNode *)pMan->baseFind(pMan->poNodeCompare);
		assert(pData);

		return pData;
	}

	Camera *CameraMan::Find(Camera::Name _name)
	{
	CameraMan *pMan = CameraMan::privGetInstance();
	assert(pMan != nullptr);

	// Compare functions only compares two Nodes

	// So:  Use the Compare Node - as a reference
	//      use in the Compare() function
	Camera *pCamera = pMan->poNodeCompare->GetCamera();
	assert(pCamera);

	pCamera->name = _name;

	CameraNode *pData = (CameraNode *)pMan->baseFind(pMan->poNodeCompare);
		assert(pData);

		return pData->GetCamera();
	}

	void CameraMan::Remove(Camera *pCam)
	{
		assert(pCam != nullptr);

	CameraMan *pMan = CameraMan::privGetInstance();
	assert(pMan != nullptr);

		CameraNode *pNode = CameraMan::FindNode(pCam);
		assert(pNode);

	pMan->baseRemove(pNode);
	}

	void CameraMan::Dump()
	{
	CameraMan *pMan = CameraMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseDump();
	}

	//----------------------------------------------------------------------
	// Private methods
	//----------------------------------------------------------------------
	CameraMan *CameraMan::privGetInstance()
	{
	// Safety - this forces users to call Create() first before using class
	assert(posInstance != nullptr);

	return posInstance;
	}

	//----------------------------------------------------------------------
	// Override Abstract methods
	//----------------------------------------------------------------------
	DLink *CameraMan::derivedCreateNode()
	{
	DLink *pNodeBase = new CameraNode();
	assert(pNodeBase != nullptr);

	return pNodeBase;
	}
}

// --- End of File ---





