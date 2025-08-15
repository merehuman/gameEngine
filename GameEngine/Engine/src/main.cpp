//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#include "GameMan.h"
#include "google\protobuf\message_lite.h"

using namespace Azul;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	// Game is inside a singleton
	int status = GameMan::Create("W5(21)",  
								 2*400, // width
								 2*300, // height
								 hInstance, 
								 prevInstance, 
								 cmdLine, 
								 cmdShow);
	// Clean up
	GameMan::Destroy();

	// clean shut down
	google::protobuf::ShutdownProtobufLibrary();

	return status;
}

// --- End of File ---
