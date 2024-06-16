#pragma once

int EngineInitAddress;
void EngineInitialize() {


	if (!ILTDrawPrim) {
		ILTDrawPrim = Read<uintptr_t>(CFBase + 0xF3D100);
		viewport = Read<D3DVIEWPORT9>(CFBase + 0xF3FDF0);
		Projection = Read<D3DXMATRIX>(CFBase + 0xF3FDB0);
		View = Read<D3DXMATRIX>(CFBase + 0xF3FD70);
	}


	EngineInitAddress = true;


}


#define SubtractVector(v1, v2, v3) ((v3[0] = v1[0] - v2[0]), (v3[1] = v1[1] - v2[1]), (v3[2] = v1[2] - v2[2]))

FLOAT GetDistance(D3DXVECTOR3 Local, D3DXVECTOR3 Target)
{
	FLOAT fResult[3];
	SubtractVector(Target, Local, fResult);
	return (sqrt((fResult[0] * fResult[0]) + (fResult[1] * fResult[1]) + (fResult[2] * fResult[2])) / 100);
}



bool EngineW2S(D3DXVECTOR3* InOut) {



	D3DXMATRIX View = Read<D3DXMATRIX>(CFBase + 0xF3FD70);
	D3DXMATRIX Projection = Read<D3DXMATRIX>(CFBase + 0xF3FDB0);
	D3DVIEWPORT9 viewport = Read<D3DVIEWPORT9>(CFBase + 0xF3FDF0);


	D3DXVECTOR3 vScreen;
	D3DXVECTOR3 PlayerPos(InOut->x, InOut->y, InOut->z);


	D3DXMATRIX world = D3DXMATRIX(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	D3DXVec3Project(&vScreen, &PlayerPos, &viewport, &Projection, &View, &world);
	if (vScreen.z <= 1.0f) {
		*InOut = vScreen;
		return true;
	}
	return false;

}