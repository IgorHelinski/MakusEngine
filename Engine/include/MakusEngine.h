#pragma once
class Window;
class MakusEngine
{
public:
	MakusEngine();
	~MakusEngine();

public:
	void StartMakus();

	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnQuit();

	void HelloWorld();

public:
	// for debug
	unsigned int VertexShaderSetup();
	unsigned int FragmentShaderSetup();
	unsigned int LinkShaders(unsigned int vertexShader, unsigned int fragmentShader);

	void DrawMap2D();

public:
	const int windowWidth = 1024;
	const int windowHeight = 512;
};

