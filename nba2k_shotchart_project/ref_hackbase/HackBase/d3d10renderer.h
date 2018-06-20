#ifndef __D3D10RENDERER_H__
#define __D3D10RENDERER_H__

#include "hackbase.h"

class D3D10Renderer : public Renderer
{
private:
	IDXGISwapChain *pSwapChain;
	ID3D10Device *pDevice;

	ID3D10PixelShader *pPixelShader;
	ID3D10VertexShader *pVertexShader;
	ID3D10Buffer *pBuffer;

	ID3DX10Font *mFont;
	ID3DX10Sprite *mSprite;

	bool CreateRect();
	bool CreateFont();
	bool rectCreated;
	bool fontCreated;

public:
	D3D10Renderer(IDXGISwapChain *SwapChain);
	~D3D10Renderer();
	void BeginScene() {}
	void EndScene() {}
	void RefreshData(IDXGISwapChain *SwapChain);
	void DrawRect(int x, int y, int w, int h, Color color);
	void DrawBorder(int x, int y, int w, int h, int d, Color color);
	void DrawLine(int x1, int y1, int x2, int y2, float size, bool antialias, Color color) {};
	void DrawText(int x, int y, char *Text, ...);
	void DrawCircle(int x, int y, float radius, int width, UINT samples, Color color);
	int GetWidth();
	int GetHeight();
	void loglnDebugInfo();
};

#endif