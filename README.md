# Game Engine

A comprehensive C++ game engine built with DirectX 11, featuring a modular architecture with custom libraries and external dependencies.

**Author:** Jessa Gillespie  
**Copyright:** 2025, Jessa Gillespie, all rights reserved.

## Overview

This game engine is a large-scale C++ project that provides a complete framework for 3D game development. It includes custom-built libraries for mathematics, file I/O, memory management, and asset processing, along with integration of industry-standard external libraries.

## Project Structure

### Core Engine Components

- **Engine/** - Main DirectX 11 rendering engine with shader support
- **Math/** - Custom mathematics library with SIMD-optimized vector and matrix operations
- **Time/** - Animation timing and frame management system
- **File/** - File I/O and resource management
- **Manager/** - Memory management and object lifecycle
- **PCSTree/** - Parent-Child-Sibling tree data structure for scene graphs

### Asset Pipeline

- **Converter/** - Asset conversion tools for meshes, textures, animations, and skeletons
- **Protobuf/** - Protocol Buffer data serialization for efficient asset storage
- **Data/** - Converted asset storage
- **OriginalData/** - Source asset storage

### External Libraries

- **GLTF/** - TinyGLTF for glTF/GLB file format support
- **PugiXml/** - Pugixml for XML parsing and manipulation
- **Proto/** - Google Protocol Buffers for data serialization
- **DXTex/** - DirectX Texture Library for texture processing

## Features

### Rendering Engine
- DirectX 11-based rendering pipeline
- Support for vertex and pixel shaders
- Multiple render states (blend, depth-stencil, rasterizer)
- Viewport and render target management
- VSync support

### Mathematics Library
- SIMD-optimized vector operations (Vec2, Vec3, Vec4)
- Matrix operations (Mat3, Mat4) with transformation support
- Quaternion-based rotations
- Trigonometric and utility functions
- Comprehensive unit test suite

### Asset System
- glTF/GLB file format support
- Mesh, texture, and animation conversion
- Skeleton and skinning support
- Protocol Buffer serialization for efficient loading
- XML-based configuration

### Memory Management
- Custom memory allocators
- Object lifecycle management
- Efficient data structures

### Development Tools
- Comprehensive unit testing framework
- Asset conversion pipeline
- Debug and release configurations
- Visual Studio project integration

## Building the Project

### Prerequisites
- Visual Studio 2017 or later
- Windows 10/11
- DirectX 11 SDK
- C++17 or later

### Build Instructions
1. Open `GameEngine/Engine.sln` in Visual Studio
2. Select your desired configuration (Debug/Release)
3. Build the solution
4. Run the asset converter if needed: `GameEngine/Converter.sln`

### Project Solutions
- **Engine.sln** - Main engine and library components
- **Converter.sln** - Asset conversion tools
- **File.sln** - File I/O library and tests
- **Manager.sln** - Memory management library
- **Math.sln** - Mathematics library and tests
- **PCSTree.sln** - Tree data structure library and tests
- **PugiXml.sln** - XML parsing library and tests
- **Time.sln** - Timing library

## Usage

### Basic Engine Setup
```cpp
#include "Engine.h"

class MyGame : public Azul::Engine
{
public:
    MyGame(const char* pName, int width, int height) 
        : Engine(pName, width, height) {}
    
    bool LoadContent() override { /* Load your assets */ }
    void UnloadContent() override { /* Cleanup */ }
    void Update(float deltaTime) override { /* Game logic */ }
    void Render() override { /* Rendering */ }
    void ClearDepthStencilBuffer() override { /* Clear buffers */ }
};
```

### Mathematics Operations
```cpp
#include "Vec3.h"
#include "Mat4.h"
#include "Quat.h"

Azul::Vec3 position(1.0f, 2.0f, 3.0f);
Azul::Mat4 transform = Azul::Mat4::Trans(position);
Azul::Quat rotation = Azul::Quat::RotY(3.14159f);
```

## Testing

The project includes extensive unit tests for all major components:
- Mathematics library tests (400+ test cases)
- File I/O tests
- Memory management tests
- Tree data structure tests

Run tests by building the corresponding test projects in Visual Studio.

## Asset Pipeline

1. Place source assets in `OriginalData/`
2. Use the Converter tool to process assets
3. Converted assets are stored in `Data/` with `.azul` extension
4. Assets use Protocol Buffer format for efficient loading

## License

Copyright 2025, Jessa Gillespie, all rights reserved.

## Contributing

This is a personal project. For questions or collaboration, please contact the author.

## Acknowledgments

- **TinyGLTF** - glTF file format support
- **Pugixml** - XML parsing library
- **Google Protocol Buffers** - Data serialization
- **DirectX Texture Library** - Texture processing
- **Microsoft DirectX 11** - Graphics API
