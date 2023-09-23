#pragma once
class Graphics
{
public:
	Graphics();
	~Graphics();

public:
	void InitGraphics();
	void SetOrthographicProjection(float left, float right, float bottom, float top, float near, float far);
};

