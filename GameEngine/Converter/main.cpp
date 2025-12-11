//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "GLTF.h"
#include "ConvertMesh.h"
#include "ConvertAnim.h"
#include "CreateTexture.h"
#include "CubeMesh.h"
#include "PyramidMesh.h"
#include "SphereMesh.h"
#include "Anim.h"
#include "SpriteMesh.h"
#include "ConvertXML.h"
#include "ConvertSkeleton.h"
#include "ConvertSkin.h"

#include "Vec3Data.h"
#include "QuatData.h"

#include  "JointData.h"
#include "ConvertJoint.h"
#include "ConvertHierarchy.h"

using namespace Azul;

int main()
{
	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	//font
	CreateTexturePNG("FontArial36.png", "FontArial36");
	ConvertXML("MetricsArial36.xml", "MetricsArial36");

	//sprite 
	CreateSpriteMesh();
	CreateTexturePNG("red_si.png", "Red_Alien");

	//export json
	//char *poJSON = GLTF::ExportJSON("silly_dancing.glb");

	//dancing
	//ConvertJoint("silly_dancing.glb", "silly_dancing");
	//ConvertSkin("silly_dancing.glb", "silly_dancing");
	//ConvertSkeleton("silly_dancing.glb", "silly_dancing");
	//ConvertHierarchy("silly_dancing.glb", "silly_dancing");
	//ConvertAnim("silly_dancing.glb", "silly_dancing");
	//CreateTexturePNG("silly_dancing.png", "silly_dancing");

	//walking
	CreateTexturePNG("ChickenBotDiffuse.png", "ChickenBot");
	ConvertJoint("walk+mesh.glb", "ChickenBot");
	ConvertSkin("walk+mesh.glb", "ChickenBot");
	ConvertSkeleton("walk+mesh.glb", "ChickenBot");
	ConvertHierarchy("walk+mesh.glb", "ChickenBot");
	ConvertAnim("walk+mesh.glb", "ChickenBot");



	// clean up data directory
	system("del *.png");
	system("del *.tga");
	system("del *.glb");
	system("del *.xml");

	google::protobuf::ShutdownProtobufLibrary();

	return 0;

}

// ---  End of File ---
