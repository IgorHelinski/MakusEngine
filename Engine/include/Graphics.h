#pragma once
class Graphics
{
public:
	Graphics();
	~Graphics();

public:
	void InitGraphics();
	void SetOrthographicProjection(unsigned int shaderProgram,float left, float right, float bottom, float top, float near, float far);
};

