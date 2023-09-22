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
};

